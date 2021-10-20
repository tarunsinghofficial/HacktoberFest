public class Human
{
    String name;
    int age;
    int height;
    String eyeColor;

    // public Human(String name, int age, int height, String eyeColor)
    // {
    //     super();
    //     this.name = name;
    //     this.age = age;
    //     this.height = height;
    //     this.eyeColor = eyeColor;
    // }

public Human(){
    
}
    public void speak()
    {
        System.out.println("Hello my name is "+ name);
        System.out.println("I am "+ height +" inches tall");
        System.out.println("I am "+ age +" years old");
        System.out.println("My eye color is " + eyeColor);
    }

    public void eat()
    {
        System.out.println("eating...");
    }

    public void coding()
    {
        System.out.println("coding...");
    }
}