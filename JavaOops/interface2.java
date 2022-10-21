import Interface.*;

class TestClass implements PI1,PI2 {

    // Overriding default show method
    @Override
    public void show()
    {
  
        //PI1.super.show();
  
        PI2.super.show();

        //System.out.println("Default PI2");
    }
  }
  
  public class interface2{
    // Mai driver method
    public static void main(String args[])
    {
        TestClass d = new TestClass();
        d.show();
    }
  }