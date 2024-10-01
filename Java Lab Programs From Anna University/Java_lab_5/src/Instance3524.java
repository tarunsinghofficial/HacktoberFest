import java.time.LocalDate;
import java.time.LocalTime;

class Counter {
    private static int instanceCount = 0; // Static variable to count instances
    private int nonStaticInstanceCount; // Non-static variable not visible to all instances

    public Counter() {
        instanceCount++; // Increment instance count for each new instance
        nonStaticInstanceCount = instanceCount; // Initialize non-static instance count for each new instance
    }

    public void displayCounts() {
        System.out.println("Total instances created: " + instanceCount);
        System.out.println("Non-static instance count: " + nonStaticInstanceCount);
    }
}

public class Instance3524 {
    public static void main(String[] args) {
        System.out.println("2021503524 - Mugundh J B");
        System.out.println("Date: " + LocalDate.now() + " Time: " + LocalTime.now());
        System.out.println();
        Counter counter1 = new Counter();
        Counter counter2 = new Counter();
        Counter counter3 = new Counter();

        counter1.displayCounts();
        counter2.displayCounts();
        counter3.displayCounts();
    }
}
