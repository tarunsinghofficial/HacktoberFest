import java.awt.*;
import java.awt.event.*;
class choiceMenu extends Frame implements ItemListener{
	Choice beverages;
	Choice sandwich;
	Choice pizza;
	String p="";
	String s="";
	String b="";
	String i="";
	int pcount,bcount,scount,tc;
	//closing the frame
	Mychoice(){
	addWindowListener(new WindowAdapter(){
    public void windowClosing(WindowEvent e){
    System.exit(0);
    }
	});
	//setting layout
	setLayout(new FlowLayout());
    beverages=new Choice();
    sandwich=new Choice();
    pizza=new Choice();
    //declaring labels
    Label l1=new Label("Beverage",Label.CENTER);
    Label l2=new Label("Sandwich",Label.CENTER);
    Label l3=new Label("Pizza",Label.CENTER);
    add(l1);
    add(beverages);
    add(l2);
    add(sandwich);
    add(l3);
    add(pizza);
    //adding items in lists
    beverages.add("Hot Choclate");
    beverages.add("Iced Tea");
    beverages.add("Coke Float");
    beverages.add("Virgin Mojito");
    beverages.add("Cold Coffee");
    sandwich.add("Grilled Cheese Sandwich");
    sandwich.add("Ham and Cheese Sandwich");
    sandwich.add("Paneer Sandwich");
    sandwich.add("Mayoneese Sandwich");
    sandwich.add("Bread Omelet Sandwich");  
    pizza.add("Mexian Pizza");
    pizza.add("Capsicum Pizza");
    pizza.add("Cheese Pizza");
    pizza.add("Margherita Pizza");
    pizza.add("Cheese N Corn Pizza");
    //removing items by index
    pizza.remove(4);
    //removing items by specifying string
    beverages.remove("Cold Coffee");
    //adding item listener
    beverages.addItemListener(this);
    sandwich.addItemListener(this);
    pizza.addItemListener(this);
    }
    public void itemStateChanged(ItemEvent ie){
    repaint();
    }
    public void paint(Graphics g){
    this.setBackground(new Color(255,150,100));
    Font h=new Font("Impact",Font.ITALIC|Font.BOLD,40);
    g.setFont(h);
    g.setColor(Color.yellow);
    g.drawString("Cafe Caffine Hub",60,110);
    g.drawLine(55,120,365,120);
    Font f=new Font("Comic Sans MS",Font.BOLD,20);
    g.setFont(f);
    g.setColor(Color.black);
    g.drawRect(15,70,400,210);
    g.drawRect(420,70,215,210);
    g.setColor(Color.white);
    g.drawString("Item Count",430,100);
    pcount=pizza.getItemCount();
    g.drawString("Pizza: "+pcount,425,190);
    bcount=beverages.getItemCount();
    g.drawString("Beverage: "+bcount,425,160);
    scount=sandwich.getItemCount();
    g.drawString("Sandwich: "+scount,425,220);
    tc=pcount+bcount+scount;
    g.drawString("Total Choices:"+tc,425,250);
    b=beverages.getSelectedItem();
    g.drawString("Beverage:"+b,20,160);
    p=pizza.getSelectedItem();
    g.drawString("Pizza:"+p,20,190);
    s=sandwich.getSelectedItem();
    g.drawString("Sandwich:"+s,20,220);
    i=beverages.getItem(2);//get item at specified index
    g.drawString("Beverage @ 2 index:"+i,20,250);
    }
    public static void main(String[] args){
    Mychoice m1=new Mychoice();
    m1.setVisible(true);
    m1.setSize(650,300);
    m1.setTitle("Menu");
    }
}