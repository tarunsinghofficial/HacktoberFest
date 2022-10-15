package testing;
import main.*;
//this class acts as a tester for the main solving program.
public final class Tester
{
	static int[][][] test_board= 
		{
				{{0,0,0,6,8,0,1,9,0},{2,6,0,0,7,0,0,0,4},{7,0,1,0,9,0,5,0,0}},
				{{8,2,0,0,0,4,0,5,0},{1,0,0,6,0,0,0,0,0},{0,4,0,9,0,0,0,0,0}},
				{{0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0}}
				
		};
	static int[][][] test_board2=
		{
				{{5,3,0,6,0,0,0,9,8},{0,7,0,1,9,5,0,0,0},{0,0,0,0,0,0,0,6,0}},
				{{8,0,0,4,0,0,7,0,0},{0,6,0,8,0,3,0,2,0},{0,0,3,0,0,1,0,0,6}},
				{{0,6,0,0,0,0,0,0,0},{0,0,0,4,1,9,0,8,0},{2,8,0,0,0,5,0,7,9}}
		};
   public static void runSolveTest()
   {  
	  //long t1=System.nanoTime();
	  Board soln=SudokuSolver.solveBoard(new Board(test_board)); 
	  //long t2=System.nanoTime();
	  displayBoard(soln);
	  //System.out.println("old approach= "+(t2-t1));
	  //System.gc();
	  //try {
		//Thread.sleep(5000);
	//} catch (InterruptedException e) {
		// TODO Auto-generated catch block
		//e.printStackTrace();
	//}
	 //t1=System.nanoTime();
	  //Board soln1=SudokuSolver.solveBoardBad(new Board(test_board));
	  //t2=System.nanoTime();
	  //System.out.println("new = "+(t2-t1));
	  //displayBoard(soln1);
   }
   public static void displayBoard(Board b)
   {
	   for(int i=0;i<3;++i)
	   {
		   for(int j=0;j<3;++j)
		   {
			   System.out.println("\n");
			   for(int k=0;k<9;++k)
			   {
				   if((k)%3==0)
				   {System.out.println();}
				   System.out.print(b.getStorage()[i][j][k]+" ");
			   }
			   System.out.println("\n");
		   }
	   }
   }
   public static void main(String[] args)
   {
	   Tester.runSolveTest();
   }
}
