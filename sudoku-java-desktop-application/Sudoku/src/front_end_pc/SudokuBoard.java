package front_end_pc;
import java.util.*;
import java.awt.*;
import java.awt.event.*;
import javax.swing.*;
import javax.swing.border.Border;
import javax.swing.event.*;
import main.Board;
//An object of this class represents a JComponent that displays a sudoku board which can be solved
//via the classes in the main package
@SuppressWarnings("unused")
public final class SudokuBoard 
{
public static final Border BORD=new RoundedBorder(6,Color.GREEN);
public static final Border NORD=new RoundedBorder(6,Color.CYAN);;
public static final String RULES=
"<html>Sudoku Solver is a program which is built to solve Sudoku puzzles with a unique solution, and a minimum of 23 filled tiles<br>"
+ "The program works on the basis of a brute force algorithm designed  by individual JAVA dev "
+ "Nikhil Narayanan.<br>"
+ "Using the Solver is simple, click on any cell to switch input focus to that cell,then type in <br>"
+ "any number valid for that particular cell, and it will be successfully filled.<br>"
+ "To clear a particular cell, click on it and tap 0 on the keyboard.<br>"
+ "Once you have filled the board, click on the activate solver option on the menu bar<br>"
+ "to start solving.";
public static final String URL_CONTACT="javakingxi@gmail.com";
public static final String URL_DEV="https://linktr.ee/nikhil_n67";
public static final String WORK_DEV="https://github.com/nikhil-RGB";
private boolean isActive;//Whether input is not be taken or not.True for yes, false for no
private JPanel glo_holder;//Holds all components in the board
private static final long serialVersionUID = 556678900654L;//serialVersionUID.
private Board rep;//representative Board object for this sudoku board.
private int[] coords;//coords the user wishes to input numbers at
private JButton[][][] cells;//Stores all the JButtons involved in the inputting of the Board.
private JPanel global_holder;//Holds all the components involved in board creation.
private JPanel[][] region_holders;//Stores each region involved in the creation of the board(1-9).
public static final Color foreground=Color.BLUE;//foreground of each cell
public static final Color background=Color.YELLOW;//background of each cell
protected static ActionListener ar;//Action Listener ar specifies how grid cells should respond to user's
//attempts to fill board.
protected static KeyListener kr;//KeyListener specifies how the board is supposed to react to input via
//pressing of numeric keys(1-9) and "enter"+arrow keys.
//IIB:
{
isActive=Boolean.TRUE;
kr=new KeyAdapter() 
{
	public void keyPressed(KeyEvent ke)
	{
		if(!isActive)
		{return;}
		int kc=ke.getKeyCode();
        if(kc==KeyEvent.VK_ENTER)
		{
			int x=coords[0];
			int y=coords[1];
			int z=coords[2];
			cells[x][y][z].setBorder(NORD);
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
					{
					x=0;
					}
				}
			}			
			coords[0]=x;
			coords[1]=y;
			coords[2]=z;
			cells[x][y][z].setBorder(BORD);
			String text=(1+((3*x)+y))+"";
		
		}
	}
	public void keyTyped(KeyEvent ke)
	{   
		if(!isActive) {return;}
		Runnable ob=()->{
		char ch=ke.getKeyChar();
		if(!Character.isDigit(ch))
		{return;}
		int num1=Integer.parseInt(ch+"");
		//if(num1==0)
		//{return;}
		int x=coords[0];
		int y=coords[1];
		int z=coords[2];
		if(num1==0)
		{
		rep.getStorage()[x][y][z]=0;
		cells[x][y][z].setText("");
		return;
		}
		int num=rep.getStorage()[x][y][z];
		if(num1==num)
		{return;}
		rep.getStorage()[x][y][z]=0;
		ArrayList<Integer> solns=rep.validSolutionsAt(x,y,z);
		if(solns.contains(num1))
		{
			rep.getStorage()[x][y][z]=num1;
		    cells[x][y][z].setText(""+num1);
		}
		else
		{
			rep.getStorage()[x][y][z]=num;
			int text=(3*x)+y; 
		    JOptionPane.showMessageDialog(cells[x][y][z],"Invalid input for REGION "+ ++text+" CELL "+ ++z,"Invaild input",JOptionPane.ERROR_MESSAGE);	
		}
	   };
	   SwingUtilities.invokeLater(ob);
		}
};
ar=(ev)->
 {
Runnable thr=()->{
   if(!isActive)
   {return;}
   JButton jcomp=(JButton)(ev.getSource());
   String acmd=jcomp.getActionCommand();
   Scanner reader=new Scanner(acmd);
   int x=reader.nextInt();
   int y=reader.nextInt();
   int z=reader.nextInt();
   cells[coords[0]][coords[1]][coords[2]].setBorder(NORD);
   cells[x][y][z].setBorder(BORD);
   String text=(1+((3*x)+y))+"";
   coords=new int[] {x,y,z};
   reader.close();
                   };
   Thread rr=new Thread(thr,"Input_Changer_MOUSE");
   rr.start();
  };
glo_holder=new JPanel(new BorderLayout());
glo_holder.setBackground(Color.CYAN);
rep=new Board();
coords=new int[3];
cells=new JButton[3][3][9];
global_holder=new JPanel(new GridLayout(3,3,4,4));
region_holders=new JPanel[3][3];
Color flipper=Color.BLACK;
 for(int i=0;i<3;++i)
 {
    for(int j=0;j<3;++j)
    {  
    	region_holders[i][j]=new JPanel(new GridLayout(3,3));
	    flipper=flip(flipper);  
      for(int k=0;k<9;++k)
	   {
		   JButton obc=cells[i][j][k]=new JButton();
		   obc.setFont(new Font("SansSerif",Font.BOLD,18));
		   obc.setActionCommand(i+" "+j+" "+k);
		   obc.addActionListener(ar);
		   obc.addKeyListener(kr);
		   obc.setForeground(Color.WHITE);
           obc.setBackground(flipper);		
		   obc.setBorder(NORD);
		   region_holders[i][j].add(obc);
	   }
	   global_holder.add(region_holders[i][j]);
    }
 }
 cells[0][0][0].setBorder(BORD);
 global_holder.setBackground(Color.BLACK);
 glo_holder.add(global_holder);
}
public SudokuBoard()
{
//Default constructor	
}
//Ends input process,deactivates event listeners
public int[][][] endInputProcess()
{
this.isActive=false;
this.cells[coords[0]][coords[1]][coords[2]].setBorder(NORD);
this.colourSolutions(Color.GREEN);
return rep.getStorage();	
}
//Obtains the jpanel which hold the region JPanels
public JPanel obtainGrid()
{
return this.global_holder;	
}
//Obtians the JPanel which holds every component in the board.
public JPanel compForm()
{return this.glo_holder;}
public int getFilledSquares()
{
int cc=0;
int[][][] array=rep.getStorage();
for(int i=0;i<3;++i)
{
 for(int j=0;j<3;++j)
 {
	 for(int k=0;k<9;++k)
	 {
		 if(array[i][j][k]!=0)
		 {
			 ++cc;
		 }
	 }
 }
}
return cc;
}
public int getEmptySquares()
{
int gc=this.getFilledSquares();
return 81-gc;
}

public boolean isBoardValid()
{
int c=this.getFilledSquares();
if(c>=23)
{return true;}
return false;
}
public JButton[][][] getCells()
{
return this.cells;	
}
public void colourSolutions(Color g)
{
for(int i=0;i<3;++i)
{
   for(int j=0;j<3;++j)
   {
	    for(int k=0;k<9;++k)
	    {
	    	JButton unit=this.cells[i][j][k];
	    	if(unit.getText().isEmpty())
	    	{unit.setForeground(g);}
	    }
   }

}

}

public static Color flip(Color g)
{
if(g.equals(Color.GRAY))
{
return Color.BLACK;
}
return Color.GRAY;
}

}
