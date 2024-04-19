import javax.swing.*;
import java.awt.*;
import java.awt.event.*;



@SuppressWarnings("serial")
public class JavaQuiz extends JFrame implements ActionListener{

	JLabel welcome,answer;
	
	JButton opbtns[] = new JButton[3];
	JLabel optns[] =  new JLabel[4];
	
	JLabel q1;
	
	String questions[] = {
			"Q1: Which one among these is not a keyword?",
			"Q2: Which package is directly available to our class?",
			"Q3: String class is defined in which package?",
			"Q4: Java was developed by whom? ",
			"Q5: Which one of the following is not a datatype?"
	};
	
	
	String options[][] = {
			{"class" , "get","try"},
			{"lang","swing","applet"},
			{"awt","Swing","lang"},
			{"James Gosling","Denish Ritchie","Bill Gates"},
			{"int","String","Float"}
	};
	
	JButton check;
	int trueAns = 0, checkBtnClicked=0;
	
	
	JavaQuiz()
	{
		this.setTitle("Quiz");
		this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		this.setBounds(500, 30, 515, 510);
		this.setVisible(true);
		this.setLayout(null);
		this.getContentPane().setBackground(Color.BLACK);
		
		
		welcome = new JLabel("Welcome to Java Quiz");
		welcome.setForeground(Color.green);
		welcome.setBounds(20,17,400,40);
		welcome.setFont(new Font("Ink Free",Font.BOLD,40));
		
		answer = new JLabel("Answer following question : ");
		answer.setForeground(Color.RED);
		answer.setBounds(20,70,500,40);
		answer.setFont(new Font("Ink Free",Font.BOLD,30));
		
		q1 = new JLabel(questions[0]);
		q1.setBounds(20, 130, 550, 30);
		q1.setFont(new Font("Ink Free",Font.BOLD,20));
		q1.setForeground(Color.orange);
		
		
		
		for(int i=0; i<3; i++)
		{
			opbtns[i] = new JButton(String.valueOf(i+1));
			opbtns[i].addActionListener(this);
			opbtns[i].setBackground(Color.cyan);
			opbtns[i].setFocusable(false);
			opbtns[i].setBorder(BorderFactory.createEtchedBorder());
			opbtns[i].setCursor(new Cursor(Cursor.HAND_CURSOR));
			this.add(opbtns[i]);
		}
		
		opbtns[0].setBounds(20,200,60,30);
		opbtns[1].setBounds(20,250,60,30);
		opbtns[2].setBounds(20,300,60,30);
		
		
		for(int i=0; i<3; i++)
		{
			optns[i] = new JLabel(options[0][i]);
			optns[i].setForeground(Color.white);
			optns[i].setFont(new Font("Ink Free",Font.BOLD,20));
			this.add(optns[i]);
		}
		
		
		optns[0].setBounds(100, 200, 400, 30);
		optns[1].setBounds(100, 250, 400, 30);
		optns[2].setBounds(100, 300, 400, 30);
		
		
		check = new JButton("Next");
		check.setBounds(55,395,350,35);
		check.addActionListener(this);
		check.setBackground(Color.yellow);
		check.setFont(new Font("Ink Free",Font.BOLD,20));
		check.setBorder(BorderFactory.createEtchedBorder());
		check.setFocusable(false);
		check.setCursor(new Cursor(Cursor.HAND_CURSOR));
		
		this.add(q1);
		this.add(check);
		this.add(welcome);
		this.add(answer);
		
		
		
		
	}
	
	
	public static void main(String[] args) {
		
		new JavaQuiz();
		
	}
	



	@Override
	public void actionPerformed(ActionEvent e) {	
		
		
		
		if(e.getSource() == check)
		{
			checkBtnClicked++;
		}
		
		if(checkBtnClicked == 0)
		{
			if(e.getSource() == opbtns[1])
			{
				optns[1].setForeground(Color.green);
				optns[1].setText("get      (Right)");
				opbtns[0].setEnabled(false);
				opbtns[2].setEnabled(false);
				trueAns++;
			}
			else if(e.getSource() == opbtns[0] || e.getSource() == opbtns[2] )
			{
				optns[1].setForeground(Color.green);
				
				
				if(e.getSource() == opbtns[0])
				{
					optns[0].setForeground(Color.RED);
					optns[0].setText("class      (Wrong)");
					optns[1].setText("get      (Right)");
					for(int i=0; i<3; i++)
					{
						opbtns[i].setEnabled(false);
					}
				}
				
				else if(e.getSource() == opbtns[2])
				{
					optns[2].setForeground(Color.RED);
					optns[2].setText("try      (Wrong)");
					optns[1].setText("get      (Right)");
					for(int i=0; i<3; i++)
					{
						opbtns[i].setEnabled(false);
					}
				}
			}
		}
		
		else if(checkBtnClicked == 1){
			
			for(int i=0; i<3; i++)
			{
				opbtns[i].setEnabled(true);
				opbtns[i].setBackground(Color.cyan);
				optns[i].setForeground(Color.white);
			}
			
			
			q1.setText(questions[1]);
			this.add(q1);
			
			optns[0].setText(options[1][0]);
			optns[1].setText(options[1][1]);
			optns[2].setText(options[1][2]);
			
			if(e.getSource() == opbtns[0])
			{
				optns[0].setForeground(Color.green);
				optns[0].setText("lang      (Right)");
				for(int i=1; i<3; i++)
				{
					opbtns[i].setEnabled(false);
				}
				trueAns++;
			}
			else if(e.getSource() == opbtns[1] || e.getSource() == opbtns[2] )
			{
				optns[0].setForeground(Color.green);
				
				if(e.getSource() == opbtns[1])
				{
					optns[1].setForeground(Color.RED);
					optns[1].setText("swing      (Wrong)");
					optns[0].setText("lang      (Right)");
					for(int i=0; i<3; i++)
					{
						opbtns[i].setEnabled(false);
					}
				}
				
				else if(e.getSource() == opbtns[2])
				{
					optns[2].setForeground(Color.RED);
					optns[2].setText("applet      (Wrong)");
					optns[0].setText("lang      (Right)");
					for(int i=0; i<3; i++)
					{
						opbtns[i].setEnabled(false);
					}
				}
			}
			
			
		}
		
		
		
		else if(checkBtnClicked == 2){
			
			for(int i=0; i<3; i++)
			{
				opbtns[i].setEnabled(true);
				opbtns[i].setBackground(Color.cyan);
				optns[i].setForeground(Color.white);
			}
			
			
			q1.setText(questions[2]);
			this.add(q1);
			
			optns[0].setText(options[2][0]);
			optns[1].setText(options[2][1]);
			optns[2].setText(options[2][2]);
			
			if(e.getSource() == opbtns[2])
			{
				optns[2].setForeground(Color.green);
				optns[2].setText("lang      (Right)");
				for(int i=0; i<2; i++)
				{
					opbtns[i].setEnabled(false);
				}
				trueAns++;
			}
			else if(e.getSource() == opbtns[0] || e.getSource() == opbtns[1] )
			{
				optns[2].setForeground(Color.green);
				
				if(e.getSource() == opbtns[0])
				{
					optns[0].setForeground(Color.RED);
					optns[0].setText("awt     (Wrong)");
					optns[2].setText("lang      (Right)");
					for(int i=0; i<3; i++)
					{
						opbtns[i].setEnabled(false);
					}
				}
				
				else if(e.getSource() == opbtns[1])
				{
					optns[1].setForeground(Color.RED);
					optns[1].setText("Swing      (Wrong)");
					optns[2].setText("lang      (Right)");
					for(int i=0; i<3; i++)
					{
						opbtns[i].setEnabled(false);
					}
				}
			}
			
			
		}
	
		else if(checkBtnClicked == 3){
			
			for(int i=0; i<3; i++)
			{
				opbtns[i].setEnabled(true);
				opbtns[i].setBackground(Color.cyan);
				optns[i].setForeground(Color.white);
			}
			
			
			q1.setText(questions[3]);
			this.add(q1);
			
			optns[0].setText(options[3][0]);
			optns[1].setText(options[3][1]);
			optns[2].setText(options[3][2]);
			
			if(e.getSource() == opbtns[0])
			{
				optns[0].setForeground(Color.green);
				optns[0].setText("James Gosling      (Right)");
				for(int i=1; i<3; i++)
				{
					opbtns[i].setEnabled(false);
				}
				trueAns++;
			}
			else if(e.getSource() == opbtns[1] || e.getSource() == opbtns[2] )
			{
				optns[0].setForeground(Color.green);
				
				if(e.getSource() == opbtns[1])
				{
					optns[1].setForeground(Color.RED);
					optns[1].setText("Denis Ritchie      (Wrong)");
					optns[0].setText("James Gosling      (Right)");
					for(int i=0; i<3; i++)
					{
						opbtns[i].setEnabled(false);
					}
				}
				
				else if(e.getSource() == opbtns[2])
				{
					optns[2].setForeground(Color.RED);
					optns[2].setText("Bill Gates      (Wrong)");
					optns[0].setText("James Gosling      (Right)");
					for(int i=0; i<3; i++)
					{
						opbtns[i].setEnabled(false);
					}
				}
			}
			
				
			}
		
		else if(checkBtnClicked == 4){
			
			for(int i=0; i<3; i++)
			{
				opbtns[i].setEnabled(true);
				opbtns[i].setBackground(Color.cyan);
				optns[i].setForeground(Color.white);
			}
			
			
			q1.setText(questions[4]);
			this.add(q1);
			
			optns[0].setText(options[4][0]);
			optns[1].setText(options[4][1]);
			optns[2].setText(options[4][2]);
			
			if(e.getSource() == opbtns[2])
			{
				optns[2].setForeground(Color.green);
				optns[2].setText("Float      (Right)");
				for(int i=0; i<2; i++)
				{
					opbtns[i].setEnabled(false);
				}
				trueAns++;
			}
			else if(e.getSource() == opbtns[0] || e.getSource() == opbtns[1] )
			{
				optns[2].setForeground(Color.green);
				
				if(e.getSource() == opbtns[0])
				{
					optns[0].setForeground(Color.RED);
					optns[0].setText("int     (Wrong)");
					optns[2].setText("Float      (Right)");
					for(int i=0; i<3; i++)
					{
						opbtns[i].setEnabled(false);
					}
				}
				
				else if(e.getSource() == opbtns[1])
				{
					optns[1].setForeground(Color.RED);
					optns[1].setText("String      (Wrong)");
					optns[2].setText("Float      (Right)");
					for(int i=0; i<3; i++)
					{
						opbtns[i].setEnabled(false);
					}
				}
				
			}
			
			if(e.getSource() == check) {
				check.setText("View Result");
				check.setBackground(Color.green);
			}
			
				
	}
	
		if(e.getActionCommand().equals("View Result"))
		{
			JOptionPane.showMessageDialog(null, "Your result is : "+trueAns+"/5");
		}
		
		
	
	
	}
}
