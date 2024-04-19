import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class Calculator implements ActionListener {
    JFrame frame;
    JPanel p1,p2;
    JTextField text;
    JButton [] buttons= new JButton[10];// array of number buttons
    JButton [] funButtons= new JButton[5];// array of Function buttons
    JButton dot,equal;
    char operator;
    double num1,num2,result;

    Font font = new Font("Arial",Font.BOLD,20);
    public Calculator(){
        // propeties of frame
        frame= new JFrame("Calculator");
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setSize(400,500);
        frame.setLayout(new BorderLayout());
        frame.setLocationRelativeTo(null);
        // properties of text field
        text = new JTextField("0",10);
        text.setFont(new Font("Arial",Font.BOLD,40));
        text.setComponentOrientation(ComponentOrientation.RIGHT_TO_LEFT);
        // properties of Dot button
        dot= new JButton(".");
        dot.setBackground(Color.BLACK);
        dot.setForeground(Color.WHITE);
        dot.setFocusable(false);
        dot.addActionListener(this);
        // properties of Equal button
        equal= new JButton("=") ;
        equal.setBackground(Color.BLACK);
        equal.setForeground(Color.WHITE);
        equal.setFocusable(false);
        equal.addActionListener(this);
        // for loop to initialize functios buttons
        for(int i=0; i<5; i++){
            funButtons[i]= new JButton();
        }
        // set text of functions buttons
        funButtons[0].setText("CLR");
        funButtons[1].setText("/");
        funButtons[2].setText("*");
        funButtons[3].setText("-");
        funButtons[4].setText("+");
        // for loop to set properties of Function buttons
        for(int i=0; i<5; i++){
            funButtons[i].setFocusable(false);
            funButtons[i].setFont(font);
            funButtons[i].setBackground(new Color(255,106,0));
            funButtons[i].setForeground(Color.WHITE);
            funButtons[i].addActionListener(this);
        }
        // loop for numeric buttons and set properties of  number buttons
        for(int i=0; i<10; i++){
            buttons[i]= new JButton(String.valueOf(i));
            buttons[i].setFont(font);
            buttons[i].setFocusable(false);
            buttons[i].setBackground(Color.BLACK);
            buttons[i].setForeground(Color.WHITE);
            buttons[i].addActionListener(this);
        }
        // panel 1
        p1= new JPanel();
        p1.setLayout(new GridLayout(5,1));
        // for loop for add function button to panel
        for(int i=0; i<5; i++){
            p1.add(funButtons[i]);
        }
        p1.setBackground(Color.BLACK);
        // panel 2
        p2= new JPanel();
        p2.setLayout(new GridLayout(4,3));
        // for loop for add number button to panel2
        for(int i=9; i>=0;i--){
            p2.add(buttons[i]);
        }
        p2.add(dot);
        p2.add(equal);
        frame.add(text,BorderLayout.NORTH);
        frame.add(p1,BorderLayout.EAST);
        frame.add(p2,BorderLayout.CENTER);
        frame.getContentPane().setBackground(Color.ORANGE);
        frame.setVisible(true);
    }
    @Override
    // action performed method
    public void actionPerformed(ActionEvent e) {
        for(int i=9; i>=0; i--){
            if(e.getSource()==buttons[i]){
                text.setText(text.getText().concat(String.valueOf(i)));
            }
        }
        if(e.getSource()==dot){
            text.setText(text.getText().concat("."));
        }
        // Action of clear button
        if(e.getSource()==funButtons[0]){
            text.setText("");
        }
        // Action of divide  button
        if(e.getSource()==funButtons[1]){
            num1=Double.parseDouble(text.getText());
            operator='/';
            text.setText("");
        }
        // Action of multiply  button
        if(e.getSource()==funButtons[2]){
            num1=Double.parseDouble(text.getText());
            operator='*';
            text.setText("");
        }
        // Action of subtract button button
        if(e.getSource()==funButtons[3]){
            num1=Double.parseDouble(text.getText());
            operator='-';
            text.setText("");
        }
        // Action of add button
        if(e.getSource()==funButtons[4]){
            num1=Double.parseDouble(text.getText());
            operator='+';
            text.setText("");
        }
        // Action of equal button
        if(e.getSource()==equal){
            num2=Double.parseDouble(text.getText());
            switch (operator){
                case '/':
                    result=num1/num2;
                    break;
                case '*':
                    result=num1*num2;
                    break;
                case '-':
                    result=num1-num2;
                    break;
                case '+':
                    result=num1+num2;
                    break;
            }
            text.setText(String.valueOf(result));
        }
    }
    public static void main(String[] args){
        new Calculator();
    }
}
