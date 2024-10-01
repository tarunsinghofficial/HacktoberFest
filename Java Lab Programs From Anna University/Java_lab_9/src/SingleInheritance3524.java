import java.time.LocalDateTime;
import java.time.format.DateTimeFormatter;
import java.util.Scanner;

class LivingBeing {
    protected String name;
    protected int age;

    // Default constructor for LivingBeing
    public LivingBeing() {
        this("unknown", 0);
    }

    // Parameterized constructor for LivingBeing
    public LivingBeing(String name, int age) {
        this.name = name;
        this.age = age;
    }

    protected void Breath() {
        System.out.println(name + " is Breathing!");
    }

    protected void Response() {
        System.out.println("I am " + name + " responding now!");
    }

    @Override
    public String toString() {
        return "name = '" + name + '\'' +
                ", age = " + age;
    }
}

class Animal extends LivingBeing {
    protected String type;
    protected int legs;

    // Default constructor for Animal
    public Animal() {
        this("unknown", 0);
    }

    // Parameterized constructor for Animal
    public Animal(String type, int legs) {
        this("unknown", 0, type, legs);
    }

    // Parameterized constructor for Animal with name, age, type, and legs
    public Animal(String name, int age, String type, int legs) {
        super(name, age);
        this.type = type;
        this.legs = legs;
    }

    public void Walk() {
        System.out.println(name + " is walking!");
    }

    public void NoOfLegs() {
        System.out.println(name + " has " + legs + " legs!");
    }

    @Override
    public String toString() {
        return super.toString() + ", " +
                "type = '" + type + '\'' +
                ", legs = " + legs;
    }
}

public class SingleInheritance3524 {
    public static void main(String[] args) {
        // Code for getting the current date and time
        DateTimeFormatter dtf = DateTimeFormatter.ofPattern("yyyy/MM/dd HH:mm:ss");
        LocalDateTime now = LocalDateTime.now();
        System.out.println("2021503524  " + "Mugundh J B  " + dtf.format(now));

        System.out.println();
        // Creating instances of LivingBeing and Animal
        LivingBeing live = new LivingBeing("Mugundh", 18);
        Animal cat = new Animal("Tom", 4, "pet", 4);

        System.out.println("Living Being Class Created:\n" + live);
        System.out.println("Animal Class Created:\n" + cat);

        System.out.println();

        // Invoking methods on LivingBeing and Animal
        live.Breath();
        live.Response();

        System.out.println();

        cat.Breath();
        cat.Response();
        cat.Walk();
        cat.NoOfLegs();
    }
}
