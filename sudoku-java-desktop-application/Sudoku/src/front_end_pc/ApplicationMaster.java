package front_end_pc;
import java.util.*;
import javax.swing.*;
import main.Board;
import main.SudokuSolver;
import java.awt.*;
import java.awt.event.*;

/**
 * @author Nikhil Narayanan
 * Pc version for Nikhil Narayanan's sudoku solver.
 */
public final class ApplicationMaster {
 public static final boolean isLoneApplication=true;
 public static final String icon_path="icon.png";
 JFrame jfrm;
 SudokuBoard main;
 boolean shouldRun;
 public static void main(String[] args)
 {
  Runnable obj= new Runnable()
 {
  public void run()
  {

  ApplicationMaster apmt=new ApplicationMaster();
  apmt.shouldRun=true;
  apmt.init();
  }
 };
 SwingUtilities.invokeLater(obj);
 }
		public void init()
		{
		jfrm=new JFrame("Sudoku Board Solver");
		this.setIcon();
		if(!isLoneApplication)
		{jfrm.setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);}
		else
		{jfrm.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);}
		jfrm.setSize(600,600);
		jfrm.setResizable(false);
        JMenuBar mb=new JMenuBar();
        JMenu more=new JMenu("More/Help");
        final JMenuItem rules=new JMenuItem("How to Use");
        final JMenuItem info=new JMenuItem("About Developer");
        final JMenuItem work=new JMenuItem("More from this Developer");
        final JMenuItem contact=new JMenuItem("Contact developer");
        more.add(rules);
        more.add(info);
        more.add(contact);
        more.add(work);
        ActionListener rr=(ev)->
        {
        	Desktop dt=Desktop.getDesktop();
        	JMenuItem src=(JMenuItem)(ev.getSource());
        	if(src==info)
        	{
        		try 
        		{
					dt.browse(new java.net.URI(SudokuBoard.URL_DEV));
				} 
        		catch (Throwable e)
        		{
				JOptionPane.showMessageDialog(null,"Can't Open dev-site","Oops!",JOptionPane.ERROR_MESSAGE);	
				} 
        		
        	}
        	else if(src==work)
        	{
        		try 
        		{
					dt.browse(new java.net.URI(SudokuBoard.WORK_DEV));
				} 
        		catch (Throwable e)
        		{
				JOptionPane.showMessageDialog(null,"Can't Open dev-site","Oops!",JOptionPane.ERROR_MESSAGE);	
				}
        	}
        	else if(src==contact)
        	{
        		try 
        		{
					dt.mail(new java.net.URI("mailto:"+SudokuBoard.URL_CONTACT));
				} 
        		catch (Throwable e)
        		{
				JOptionPane.showMessageDialog(null,"Can't Open Mailing-app","Oops!",JOptionPane.ERROR_MESSAGE);	
				}
        	}
        	else
        	{
        		JOptionPane.showMessageDialog(null,SudokuBoard.RULES);
        	}
        };
        info.addActionListener(rr);
        contact.addActionListener(rr);
        work.addActionListener(rr);
        rules.addActionListener(rr);
        JMenu actvt=new JMenu("Activate Solver Process");
        JMenuItem jtm=new JMenuItem("Start Solving(May take upto 4 seconds for tough puzzles)");
        main=new SudokuBoard();
        ActionListener ar=(ev)->
        {
          Thread t=new Thread() {
        	  public void run()
        	  {
        	if(!main.isBoardValid())
        	{
        		JOptionPane.showMessageDialog(null,"Board cannot have less than 23 filled tiles","Invalid Board",JOptionPane.ERROR_MESSAGE);
        		return;
        	}
        	else if(!shouldRun)
        	{
        		JOptionPane.showMessageDialog(null,"Solver Process cannot be activated on the same board, restart the application","Oops!",JOptionPane.WARNING_MESSAGE);
        		return;	
        	}
        	String mssg="<html>The program will now commence the solving process.<br>"
        			+ "This will take upto 1 second for simple puzzles and<br>"
        			+ " 1.5-4 seconds for tough puzzles.<br>"
        			+ "You will no longer be able to edit the board.<br>"
        			+ "Continue?";
        	int res=JOptionPane.showConfirmDialog(null,mssg,"Initiate Solver?",JOptionPane.YES_NO_OPTION);
        	if(res!=JOptionPane.YES_OPTION)
        	{return;}
        	shouldRun=Boolean.FALSE;
        	int[][][] board=main.endInputProcess();
        	
        	JDialog jd=new JDialog(jfrm,"Solving puzzle",false);
        	ApplicationMaster.formatJDialog(jd);
        	jd.setVisible(true);
        	
        	
        	try {
        		//Code for progress bar here
        	int[][][] soln=SudokuSolver.solveBoard(new Board(board)).getStorage();
        	fillSolution(soln);
        	    }
        	catch(Throwable obj)
        	{
        		JOptionPane.showMessageDialog(null,"<html>Sudoku Solver can't seem to wrap it's head around this board<br>Please restart the application and enter another puzzle","YIKES!",JOptionPane.ERROR_MESSAGE);
        	}
        	finally
        	{
        	 closeDialog(jd);
        	}
        	System.gc();
        	  }
        	  };
        t.start();	  
        };
        jtm.addActionListener(ar);
        actvt.add(jtm);
        mb.add(actvt);
        mb.add(more);
        jfrm.add(main.compForm());
        jfrm.setJMenuBar(mb);
        jfrm.setVisible(true);
	    }
		public void fillSolution(int[][][] soln)
		{
			JButton[][][] cells=main.getCells();
			for(int i=0;i<3;++i)
			{
				for(int j=0;j<3;++j)
				{
					for(int k=0;k<9;++k)
					{
						cells[i][j][k].setText(""+soln[i][j][k]);
						cells[i][j][k].repaint();
					}
				}
			}
		}
		
		public final void setIcon()
		{
			try {
			ImageIcon s=new ImageIcon(icon_path);
			jfrm.setIconImage(s.getImage());
			   }
			catch(Throwable obj)
			{
			JOptionPane.showMessageDialog(null,"Icon file tampered with","Yikes!",JOptionPane.WARNING_MESSAGE);
			}
		}

		public static void formatJDialog(JDialog d)
		{
			JProgressBar bb=new JProgressBar();
			bb.setIndeterminate(Boolean.TRUE);
			d.add(bb);
			d.setSize(100,50);
			d.setLocationRelativeTo(null);
			d.setDefaultCloseOperation(JDialog.DO_NOTHING_ON_CLOSE);
		}
		public static void closeDialog(JDialog ff)
		{
			ff.setVisible(false);
		    ff.dispose();
		}
}
