interface PI1 {
  default void show()
  {
      System.out.println("Default PI1");
  }
}
//The default access modifier is also called package-private, which means that all members are visible within the same package but aren't accessible from other packages 
// Interface 2
interface PI2 extends PI1{//interface use extend to call his parent interface

  // Default method
  @Override
  default void show()
  {
      System.out.println("Default PI2");
  }
}

class TestClass implements PI2 {

  // Overriding default show method
  @Override
  public void show()
  {

      //PI1.show();

      PI2.super.show();
  }

  
}

public class Interface{
  // Mai driver method
  public static void main(String args[])
  {
      //PI1 p = new PI1();//PI1 is abstract; cannot be instantiated
      TestClass d = new TestClass();
      d.show();
  }
}

//Interfaces are used in Java to achieve abstraction and multiple inheritance.
//It is also used to achieve loose coupling.
//Interface cannot be final otherwise it thow compile time error
//In Interface only one specifier is used- Public.
//In an interface, you can’t instantiate variables and create an object.
//The reason is, abstract classes may contain non-final variables, whereas variables in the interface are final, public and static.
//From Java 9 onwards, interfaces can contain the following also:

//static methods
//Private methods
//Private Static methods