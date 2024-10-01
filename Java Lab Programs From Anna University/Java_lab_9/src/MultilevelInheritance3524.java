import java.time.LocalDateTime;
import java.time.format.DateTimeFormatter;

class Cat extends Animal {
    public Cat() {
        super(); // Call the default constructor of the parent class (Animal)
    }

    public Cat(String type, int legs) {
        super(type, legs); // Call the parameterized constructor of the parent class (Animal)
    }

    public Cat(String name, int age, String type, int legs) {
        super(name, age, type, legs); // Call the parameterized constructor of the parent class (Animal)
    }

    // Method to simulate a cat's meow
    public void Meow() {
        System.out.println(name + " is giving sound Meowww!!!");
    }

    @Override
    public String toString() {
        return super.toString(); // Override the toString method
    }
}

class Dog extends Animal {
    public Dog() {
        super(); // Call the default constructor of the parent class (Animal)
    }

    public Dog(String type, int legs) {
        super(type, legs); // Call the parameterized constructor of the parent class (Animal)
    }

    public Dog(String name, int age, String type, int legs) {
        super(name, age, type, legs); // Call the parameterized constructor of the parent class (Animal)
    }

    // Method to simulate a dog's bark
    public void Bark() {
        System.out.println(name + " is giving sound Bow Bow!!!");
    }

    @Override
    public String toString() {
        return super.toString(); // Override the toString method
    }
}

public class MultilevelInheritance3524 {
    public static void main(String[] args) {
        // Code for getting the current date and time
        DateTimeFormatter dtf = DateTimeFormatter.ofPattern("yyyy/MM/dd HH:mm:ss");
        LocalDateTime now = LocalDateTime.now();
        System.out.println("2021503524  " + "Mugundh J B  " + dtf.format(now));

        // Creating instances of LivingBeing, Animal, Cat, and Dog
        LivingBeing live = new LivingBeing("Mugundh", 18);
        Animal rat = new Animal("Jerry", 3, "pet", 4);
        Cat cat = new Cat("Tom", 5, "pet", 4);
        Dog dog = new Dog("Spike", 6, "pet", 4);

        // Printing information about the created objects
        System.out.println("\nLiving Being Class Created:\n" + live);
        System.out.println("\nAnimal Class Created:\n" + rat);
        System.out.println("\nCat Class Created:\n" + cat);
        System.out.println("\nDog Class Created:\n" + dog);

        // Invoking methods on Living Being
        System.out.println("\nLiving Being methods: ");
        live.Breath();
        live.Response();

        // Invoking methods on Animals
        System.out.println("\nAnimal methods: ");
        rat.Breath();
        rat.Response();
        rat.Walk();
        rat.NoOfLegs();

        // Invoking methods on Cat
        System.out.println("\nCat methods: ");
        cat.Breath();
        cat.Response();
        cat.Walk();
        cat.NoOfLegs();
        cat.Meow();

        // Invoking methods on Dog
        System.out.println("\nDog methods: ");
        dog.Breath();
        dog.Response();
        dog.Walk();
        dog.NoOfLegs();
        dog.Bark();
    }
}
