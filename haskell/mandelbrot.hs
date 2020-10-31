import Graphics.UI.GLUT
import Data.Complex

iterations = 400

chunk :: Int -> [a] -> [[a]]
chunk n [] = []
chunk n xs = let (xs', rest) = splitAt n xs in xs' : chunk n rest

vertices :: IO [Vertex2 GLfloat]
vertices = get windowSize >>= \(Size w h) ->
           return $ [pixel (Size w h) (x, y) | x <- [0..w-1], y <- [0..h-1]]
  where
    pixel (Size w h) (x, y) = Vertex2 ((fromIntegral 3 / fromIntegral w * fromIntegral x) - 2.0) ((fromIntegral 2 / fromIntegral h * fromIntegral y) - 1.0)

getcol :: Int -> Color3 Float
getcol iter | iter == iterations = Color3 0 0 0
              | otherwise          = Color3 (amt*0.5) amt (amt*0.5)
  where
    amt = fromIntegral iter / fromIntegral iterations

mandelbrot :: RealFloat a => Vertex2 a -> Int
mandelbrot (Vertex2 r i) = length . takeWhile (\z -> magnitude z <= 2) . take iterations $ iterate (\z -> z^2 + (r :+ i)) 0

drawVert :: (RealFloat a, VertexComponent a) => Vertex2 a -> IO ()
drawVert v = do color . getcol $ mandelbrot v
                vertex v

display' :: [[Vertex2 GLfloat]] -> IO ()
display' chunks = do mapM_ (\vs -> do renderPrimitive Points $ mapM_ drawVert vs
                                      flush) chunks
                     displayCallback $= display

display :: IO ()
display = do clear [ ColorBuffer ]
             displayCallback $= (vertices >>= display' . chunk 256)
             get currentWindow >>= postRedisplay

main :: IO ()
main = do
   getArgsAndInitialize
   initialDisplayMode $= [ SingleBuffered, RGBMode ]
   initialWindowSize $= Size 1200 1024
   initialWindowPosition $= Position 100 100
   createWindow "Mandelbrot"
   clearColor $= Color4 0 0 0 0
   matrixMode $= Projection
   loadIdentity
   ortho (-2) 1 (-1) 1 (-1) 1
   displayCallback $= display
   mainLoop
