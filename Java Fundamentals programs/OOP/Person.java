public class Person
{
    public String name;
    public String lastname;
    public int age;
    public String address;
 
    public Person()
    {
        this.name = "Stanley";
        this.lastname = "Brikkz";
        this.age = 20;
        this.address = "23 Colenbrander";
    }

    public Person(String name, String lastname, int age, String address)
    {
        this.name = name;
        this.lastname = lastname;
        this.age = age;
        this.address = address;
    }

    public void setName(String name)
    {
        this.name = name;
    }

    public String getName()
    {
        return this.name;
    }

    public static void main(String args[])
    {
        //Person person1 = new Person();
        //System.out.println(person1.getName());
    }

}