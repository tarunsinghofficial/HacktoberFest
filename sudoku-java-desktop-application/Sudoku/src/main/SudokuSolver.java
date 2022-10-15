package main;
import java.util.*;

import javax.swing.JOptionPane;

import front_end_pc.ApplicationMaster;
import util.OperationTimeOutException;
//This class carries out solving operation on the board so provided.
public final class SudokuSolver
{

	public static Board solveBoard(Board board) 
	{
	ArrayList<Board> pos_solns=new ArrayList<>(0);
	try 
	{
	long ms=System.currentTimeMillis();
	pos_solns.add(board);
	while(!pos_solns.get(0).solved)
	{
	pos_solns.addAll(pos_solns.get(0).stepInto());
	pos_solns.remove(0);
	long ms1=System.currentTimeMillis();
	if((ms1-ms)>6500)
	{
	 throw new util.OperationTimeOutException("The Solver process is taking too long");
	}
	}
    
	   }
	catch(OperationTimeOutException obj)//Only Operation checking
	{
		int resp=JOptionPane.showConfirmDialog(null,"<html>We can't seem to solve this one completely<br>Show partially solved board?<br>Note:Non solved spaces will contain 0","Sad SudokuSolver noises",JOptionPane.ERROR_MESSAGE);
        if(ApplicationMaster.isLoneApplication&&resp!=JOptionPane.YES_OPTION)
        {System.exit(1);}
        else if(resp!=JOptionPane.YES_OPTION)
        {return new Board(board.getStorage());}
        else
        {
         return pos_solns.get(0);
        }
	}
	return pos_solns.get(0);
    }
	
	
	public static Board solveBoardBad(Board board) 
	{
	Board st=board.clone();
	SolutionsConfiguration.original=st;
	ArrayList<SolutionsConfiguration> pos_solns=new ArrayList<>(0);
	try 
	{
	long ms=System.currentTimeMillis();
	pos_solns.add(new SolutionsConfiguration());
	while(!pos_solns.get(0).isSolved())
	{
	pos_solns.get(0).fillInto(board);
	ArrayList<SolutionsConfiguration> boards=SolutionsConfiguration.extractSolnConfigs(board.stepInto());
	board.format(st);
	pos_solns.addAll(boards);
	pos_solns.remove(0);
	long ms1=System.currentTimeMillis();
	if((ms1-ms)>8500)
	{
	 throw new util.OperationTimeOutException("The Solver process is taking too long");
	}
	}
    
	   }
	catch(OperationTimeOutException obj)
	{
		int resp=JOptionPane.showConfirmDialog(null,"<html>We can't seem to solve this one completely<br>Show partially solved board?<br>Note:Non solved spaces will contain 0","Sad SudokuSolver noises",JOptionPane.ERROR_MESSAGE);
        if(ApplicationMaster.isLoneApplication&&resp!=JOptionPane.YES_OPTION)
        {System.exit(1);}
        else if(resp!=JOptionPane.YES_OPTION)
        {return new Board(board.getStorage());}
        else
        {
        pos_solns.get(0).fillInto(board);
         return board;
        }
	}
	pos_solns.get(0).fillInto(board);
	return board;
    }
}
