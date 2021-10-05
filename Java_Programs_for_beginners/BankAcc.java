public class BankACC
{
String name; float amount;

public void setValue(String nm)
{
name=nm;
}


public void setValue(float amt)
{
amount=amt;
}


public void getValue()
{
System.out.println("\nThe account holder name is : "+name); System.out.println("The amount is : "+amount);
}



public static void main(String args[])
 
{
BankACC obj1=new BankACC(); obj1.setValue("\nAnushkaGhosh");
 obj1.setValue(1000.0f);



BankACC obj2=new BankACC(); obj2.setValue("\nRaju Mondal"); obj2.setValue(2000.0f);


obj1.getValue(); obj2.getValue();
}
}

