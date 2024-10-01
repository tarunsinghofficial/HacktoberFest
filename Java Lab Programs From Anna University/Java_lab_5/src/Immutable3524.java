import java.time.LocalDate;
import java.time.LocalTime;

class Person {
    private final String name;
    private final int age;

    public Person(String name, int age) {
        this.name = name;
        this.age = age;
    }

    public String getName() {
        return name;
    }

    public int getAge() {
        return age;
    }
}

public class Immutable3524 {
    public static void main(String[] args) {
        System.out.println("2021503524 - Mugundh J B");
        System.out.println("Date: " + LocalDate.now() + " Time: " + LocalTime.now());
        try {
            Person person = new Person("Mugundh", 10);

            System.out.println("Initial Person state:");
            System.out.println("Name: " + person.getName());
            System.out.println("Age: " + person.getAge());

            // Intentionally attempt to change the state (will trigger an error)
            // person.name = "Hello";
            // person.age = 0;

            // Display state after the attempted changes
            System.out.println("\nPerson state after attempted changes:");
            System.out.println("Name: " + person.getName());
            System.out.println("Age: " + person.getAge());
        } catch (Exception e) {
            System.out.println("Error: " + e.getMessage());
        }
    }
}
