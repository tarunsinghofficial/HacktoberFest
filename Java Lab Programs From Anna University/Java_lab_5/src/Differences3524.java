import java.time.LocalDate;
import java.time.LocalTime;

class Dummy {
    // Instance variable
    int instanceVar;
    // Static variable
    static int staticVar;
    public Dummy(int instanceVar) {
        this.instanceVar = instanceVar;
    }

    // Instance method
    void instanceMethod() {
        System.out.println("Inside instance method:");
        System.out.println("Instance variable value: " + instanceVar);
        System.out.println("Static variable value: " + staticVar);
        staticMethod(); // Calling static method from instance method
    }

    // Static method
    static void staticMethod() {
        System.out.println("Inside static method:");
        // System.out.println("Instance variable value: " + instanceVar);
        // Error: Cannot access instance variable from static method
        System.out.println("Static variable value: " + staticVar);
    }
}

public class Differences3524 {
    public static void main(String[] args) {
        System.out.println("2021503524 - Mugundh J B");
        System.out.println("Date: " + LocalDate.now() + " Time: " + LocalTime.now());
        Dummy obj = new Dummy(5);

        // Access instance variable and instance method
        System.out.println("\nInstance variables and methods can't be accessed without creating object\n");
        System.out.println("Instance variable value: " + obj.instanceVar);
        obj.instanceMethod();

        // Access static variable and static method
        System.out.println("\nStatic variables and methods can be accessed without creating object\n");
        System.out.println("Static variable value: " + Dummy.staticVar);
        Dummy.staticMethod();
    }
}
