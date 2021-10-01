import java.awt.*;
import javax.swing.*;
import java.awt.event.*;
class objectiveQuestions{
	JFrame frame;
	JButton submit;
	JLabel q1,q2,q3,q4,q5;
	JRadioButton a,b,c,d,e,f,g,h,i,j;
	ButtonGroup a1,a2,a3,a4,a5;
	objectiveQuestions(){
	frame=new JFrame();
	submit =new JButton("Submit");
	a1=new ButtonGroup();
	a2=new ButtonGroup();
	a3=new ButtonGroup();
	a4=new ButtonGroup();
	a5=new ButtonGroup();
	
	q1=new JLabel("1.Inventor of Java is ?");
    a=new JRadioButton("James Gosling");
	b=new JRadioButton("Dennis Ritchie");
	a1.add(a);
	a1.add(b);

    q2=new JLabel("2.Java was released in the year ?");
	c=new JRadioButton("1990");
	d=new JRadioButton("1995");
	a2.add(c);
	a2.add(d);	

	q3=new JLabel("3.Swing is platform:");
	e=new JRadioButton("Dependent");
	f=new JRadioButton("Independent");
	a3.add(e);
	a3.add(f);

	q4=new JLabel("4.AWT components are light weight?");
	g=new JRadioButton("True"); 	
	h=new JRadioButton("False");
	a4.add(g);
	a4.add(h);

	q5=new JLabel("5.Swing component are light weight?");
	i=new JRadioButton("True");
	j=new JRadioButton("False");
	a5.add(i);
	a5.add(j);

    frame.add(q1);
    frame.add(a);frame.add(b);
    frame.add(q2);
    frame.add(c);frame.add(d);
    frame.add(q3);
    frame.add(e);frame.add(f);
    frame.add(q4);
    frame.add(g);frame.add(h);
    frame.add(q5);
    frame.add(i);frame.add(j);
    frame.add(submit);
    
    
    frame.setLayout(new FlowLayout(FlowLayout.LEFT)); 
	frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
	frame.setSize(400,300);
	frame.setTitle("5 Obejctive Questions");
	frame.setVisible(true);
	}
	public static void main(String[] args) {
   	objectiveQuestions obj=new objectiveQuestions();
   }
}