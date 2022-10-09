import java.util.*;
import packageexample.*;

class Pen {
    String color;
    String type;
    Pen(){

    }
    Pen(String color1,String type1){
        this.color=color1;
        this.type=type1;
    }

    public void write() {
        System.out.println("Write Something "+this.color+" "+this.type );
    }
    public void write(String s) {
        System.out.println("Write Something "+this.color+" "+this.type+" "+s );
        
    }   
}


//Inheritance and Abstraction (Abstract class)
//Interface are abstract classes using abstract methods only
abstract class Shape{
    String color;
    abstract void Color();
    public void Sides() {
        System.out.println("It has sides");
    }
}
class Triangle extends Shape{
    
    String shape1="Triangle";
    public void Color(){
        System.out.println("Shape is "+shape1+" and color is "+this.color);
    }
}

class OOPS {
    public static void main(String args[]) {

        Pen pen1 = new Pen();
        pen1.color= "Blue";
        pen1.type= "Gel";

        Pen pen2 = new Pen();
        pen2.color= "Black";
        pen2.type= "Gel";
        pen1.write();
        pen2.write();

        Pen pen3 = new Pen("Red","Ball");
        pen3.write("Hai");

        Triangle triangle=new Triangle();
        triangle.color="Red";
        triangle.Color();
        triangle.Sides();

        //Packages
        /*packageexample.Account account1= new packageexample.Account();
        account1.name="Customer-Name";
        System.out.println(account1.name);
    
        packageExample s2= new packageExample();
        s2.msg();
        */
        }
}