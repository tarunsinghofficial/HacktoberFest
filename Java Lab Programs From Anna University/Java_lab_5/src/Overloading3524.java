import java.time.LocalDate;
import java.time.LocalTime;

class Sum {
    // Method to sum two integers
    public int sum(int x, int y) {
        return (x + y);
    }

    // Method to sum three integers
    public int sum(int x, int y, int z) {
        return (x + y + z);
    }


    // Method to sum two doubles
    public double sum(double x, double y) {
        return (x + y);
    }

}

class Data {
    double value;

    // Constructor to initialize Data object
    public Data(double value) {
        this.value = value;
    }
}

public class Overloading3524 {
    public static void main(String[] args) {
        System.out.println("2021503524 - Mugundh J B");
        System.out.println("Date: " + LocalDate.now() + " Time: " + LocalTime.now());
        Sum s = new Sum();

        // Parameter overloading with two and three parameters
        System.out.println("\ns.sum(5, 10) => " + "Parameter overloading - 2 parameters: " + s.sum(5, 10));
        System.out.println("\ns.sum(5, 10, 15) => " + "Parameter overloading - 3 parameters: " + s.sum(5, 10, 15));

        // Data type overloading with two doubles
        System.out.println("\ns.sum(5.5, 10.2) => " + "Data type overloading - double type: " + s.sum(5.5, 10.2));

        // Create Data objects
        Data d1 = new Data(7.5);
        Data d2 = new Data(2.5);

        // Using object as a parameter
        double result = s.sum(d1.value, d2.value);
        System.out.println("\ns.sum(d1.value, d2.value) => " + "Using object as parameter: " + result);
    }
}
