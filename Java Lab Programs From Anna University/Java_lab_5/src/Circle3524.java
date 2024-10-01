import java.lang.Math;
import java.time.LocalDate;
import java.time.LocalTime;

class Circle {
    double centerX;
    double centerY;
    double radius;

    // Constructor to initialize circle's properties
    Circle(double x, double y, double r) {
        centerX = x;
        centerY = y;
        radius = r;
    }

    // Display circle's center and radius
    void display() {
        System.out.println("Center: (" + centerX + ", " + centerY + ")");
        System.out.println("Radius: " + radius);
    }

    // Calculate the area of the circle
    double calculateArea() {
        return Math.PI * radius * radius;
    }

    // Compare areas of two circles and return comparison result
    static String compareArea(Circle c1, Circle c2) {
        double area1 = c1.calculateArea();
        double area2 = c2.calculateArea();

        if (area1 < area2) {
            return "Circle 1 is smaller than Circle 2.";
        } else if (area1 > area2) {
            return "Circle 1 is larger than Circle 2.";
        } else {
            return "Circle 1 is equal in area to Circle 2.";
        }
    }
}

public class Circle3524 {
    public static void main(String[] args) {
        System.out.println("2021503524 - Mugundh J B");
        System.out.println("Date: " + LocalDate.now() + " Time: " + LocalTime.now());

        // Create two circlesSS
        Circle circle1 = new Circle(0, 0, 5);
        Circle circle2 = new Circle(2, 3, 7);

        // Display circle information and area for circle 1
        circle1.display();
        System.out.println("Area of Circle 1: " + circle1.calculateArea());

        System.out.println();

        // Display circle information and area for circle 2
        circle2.display();
        System.out.println("Area of Circle 2: " + circle2.calculateArea());

        System.out.println();

        // Compare and display the comparison result of circle areas
        System.out.println(Circle.compareArea(circle1, circle2));
    }
}
