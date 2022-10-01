#Need qrcode and image libraries

import qrcode
import image

#Enter URL or Detail which should added to the QR code hee
img = qrcode.make("test")

#Enter the name how you want to save your QR code 
img.save("test.jpg")

