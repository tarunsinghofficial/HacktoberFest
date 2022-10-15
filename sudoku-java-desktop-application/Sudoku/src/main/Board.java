//Integral part of the sudoku solver program, represents the board currently being parsed by our
//program
package main;
import java.util.*;
import util.IllegalUpdateException;
public final class Board implements util.OSneutral,java.io.Serializable
{
	protected boolean solved;//tells the program whether or not the board is solved.
	//Serial version UID for object of this class.
	private static final long serialVersionUID = 8035243029574361251L;
//An object of this class functions as an independant sudoku board which is solved or unsolved.
//The object has the functionality to operate itself to reach a solution for the board it represents,
//including generation of "children", duplication of the board with an extra test case number.
	int[][][] storage;//Functions as the array which stores the numbers in the sudoku board
	private int[] empty_co;//Empty cell grid co-ordinates
	//Constructor which takes input boar and stores it in memeber variable storage.
	//IIB1
	{
		empty_co=new int[3];
		solved=Boolean.FALSE;
	}
	public Board(int[][][] board)
	{
	this.storage=board;	
	}
	//default constructor, creates an empty board
	public Board()
	{
	storage=new int[3][3][9];
	}
	//Method that clears current board object
	public void formatBoard()
	{
		for(int i=0;i<3;++i)
		{
			for(int j=0;j<3;++j)
			{
				for(int k=0;k<9;++k)
				{
					storage[i][j][k]=0;
				}
			}
		}
	}
	//return cloumn current element is associated with
	public ArrayList<Integer> returnColumn(int i,int j,int k)
	{
		int k1=0;
		if((k==0)||(k==3)||(k==6))
		{
			k1=0;
		}
		else if((k==1)||(k==4)||(k==7))
		{
			k1=1;
		}
		else
		{
			k1=2;
		}
		ArrayList<Integer> arri=new ArrayList<>(0);
		for(int i1=0;i1<3;++i1)
		{
			for(int k2=k1;k2<=(k1+6);k2+=3)
			{
				arri.add(this.storage[i1][j][k2]);
			}
		}
		return arri;
	}
	//returns row current element is associated with
	public ArrayList<Integer> returnRow(int i,int j,int k)
	{
		int k1=0;
		if((k==0)||(k==1)||(k==2))
		{
			k1=0;
		}
		else if((k==3)||(k==4)||(k==5))
		{
			k1=3;
		}
		else
		{
			k1=6;
		}
		ArrayList<Integer> arrs=new ArrayList<>(0);
		for(int j1=0;j1<3;++j1)
		{
			for(int k2=k1;k2<=(k1+2);++k2)
			{
				arrs.add(this.storage[i][j1][k2]);
			}
		}
		return arrs;
	}
	//this method returns "region"/"block" associated with element being parsed currently
	public ArrayList<Integer> returnRegion(int i,int j)
	{
		ArrayList<Integer> ars=new ArrayList<>(0);
		for(int k=0;k<9;++k)
		{
			ars.add(this.storage[i][j][k]);
		}
	return ars;
	}
	//this method return valid options for a current cell
	public ArrayList<Integer> validSolutionsAt(int i,int j,int k)
	{   
		if(this.storage[i][j][k]!=0)
		{return null;}
		ArrayList<Integer> solutions=new ArrayList<>(0);
		for(int k1=0;k1<9;++k1)
		{
		 solutions.add((k1+1));	
		}
		ArrayList<Integer> region=this.returnRegion(i, j);
		ArrayList<Integer> row=this.returnRow(i, j, k);
		ArrayList<Integer> column=this.returnColumn(i, j, k);
		solutions.removeAll(region);
		solutions.removeAll(row);
		solutions.removeAll(column);
		return solutions;
	}
	//This method calculates the position of the first grid cell which isn't solved, right to left,
	//region by region.
	public int[] calcEmptyCoord()
	{
		for(int i=0;i<3;++i)
		{
			for(int j=0;j<3;++j)
			{
				for(int k=0;k<9;++k)
				{
					if(this.storage[i][j][k]==0)
					{return new int[] {i,j,k};}
				}
			}
		}
		return new int[0];	
	}
	//this method returns the pre-existing empty co-ord, may not always be accurate
	public  int[] returnEmptyCoord()
	{
		return this.empty_co;
	}
	//solves the board by one step, and creates Children
	public ArrayList<Board> stepInto()
	{
		
		int i=this.empty_co[0];
		int j=this.empty_co[1];
		int k=this.empty_co[2];
		if(this.storage[i][j][k]!=0)
		{
			int upscr[]=this.updateLocation(i, j, k);
		    if(upscr==null)
		    {this.solved=true;}
			return this.duplicate(1);	
		}
		ArrayList<Integer> ars=this.validSolutionsAt(i, j, k);
		if(ars==null)
		{
			throw new IllegalUpdateException("Grid box has a non zero substition at "+i+" "+j+" "+k);
		}
		if(ars.isEmpty())
		{return new ArrayList<>(0);}
		ArrayList<Board> children=this.duplicate(ars.size());
		for(int n=0;n<children.size();++n)
		{
			Board op=children.get(n);
			int solution=ars.get(n);
			op.storage[i][j][k]=solution;
			int[] up_pos=op.updateLocation(i,j,k);
			if(up_pos==null)
			{op.solved=true;}
		}
		return children;
	}
	private int[] updateLocation(int x,int y,int z)
	{
	++z;
	if(z>8)
	{
		z=0;
		++y;
		if(y>2)
		{
			y=0;
			++x;
			if(x>2)
			{return null;}
		}
	}
	this.empty_co=new int[] {x,y,z};
	return this.empty_co;
	}
	public ArrayList<Board> duplicate(int times)
	{   
		boolean solve=this.solved;
		int[] coords=new int[] {this.empty_co[0],this.empty_co[1],this.empty_co[2]};
		ArrayList<Board> ob=new ArrayList<>(0);
		for(int k=0;k<times;++k)
		{
			int[][][] brd=new int[3][3][9];
			for(int i=0;i<3;++i)
			{
				for(int j=0;j<3;++j)
				{
					for(int p=0;p<9;++p)
					{
						brd[i][j][p]=this.storage[i][j][p];
					}
				}
			}
			Board baba=new Board(brd);
			baba.empty_co=coords;
			baba.solved=solve;
			ob.add(baba);
		}
	return ob;
	}
	public int emptyTiles()
	{   
        int[][][] st=this.storage;
		int C=0;
		for(int i=0;i<3;++i)
		{
			for(int j=0;j<3;++j)
			{
				for(int k=0;k<9;++k)
				{
				int num=st[i][j][k];
				if(num==0)
				{++C;}
				}
			}
		}
	return C;
	}
	public int filledTiles()
	{
		return (81-this.emptyTiles());
	}
	public int[][][] getStorage()
	{
		return this.storage;
	}
	@Override
	public Board clone()
	{
		return this.duplicate(1).get(0);	
	}
	public void format(Board b)
	{
		int[][][] apun_ka_thali=this.getStorage();
		int[][][] stor=b.storage;
		for(int i=0;i<3;++i)
		{
			for(int j=0;j<3;++j)
			{
				for(int k=0;k<9;++k)
				{
					apun_ka_thali[i][j][k]=stor[i][j][k];
				}
			}
		}
		
	}
}
