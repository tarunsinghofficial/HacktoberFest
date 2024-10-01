import java.time.LocalDateTime;
import java.time.format.DateTimeFormatter;
import java.util.Scanner;

public class PolynomialOperations3524 {
    static class Node {
        int coefficient;
        int exponent;
        Node next;

        Node(int coef, int exp) {
            coefficient = coef;
            exponent = exp;
            next = null;
        }
    }

    Node head;

    // Function to insert a term into the polynomial linked list
    public void insertTerm(int coef, int exp) {
        Node newNode = new Node(coef, exp);
        if (head == null) {
            head = newNode;
            return;
        }

        Node current = head;
        while (current.next != null) {
            current = current.next;
        }
        current.next = newNode;
    }

    // Function to display the polynomial
    public void display() {
        System.out.print("Polynomial: ");
        Node current = head;
        while (current != null) {
            if (current.coefficient != 0) {
                if(current.exponent != 0) {
                    System.out.print(current.coefficient + "x^" + current.exponent);
                    if (current.next != null && current.next.coefficient != 0) {
                        System.out.print(" + ");
                    }
                }else{
                    System.out.print(current.coefficient);
                }
            }
            current = current.next;
        }
        System.out.println();
    }

    // Function to add two polynomials
    public static PolynomialOperations3524 addPolynomials(PolynomialOperations3524 poly1, PolynomialOperations3524 poly2) {
        PolynomialOperations3524 result = new PolynomialOperations3524();
        Node current1 = poly1.head;
        Node current2 = poly2.head;

        while (current1 != null && current2 != null) {
            if (current1.exponent > current2.exponent) {
                result.insertTerm(current1.coefficient, current1.exponent);
                current1 = current1.next;
            } else if (current2.exponent > current1.exponent) {
                result.insertTerm(current2.coefficient, current2.exponent);
                current2 = current2.next;
            } else {
                int sumCoeff = current1.coefficient + current2.coefficient;
                if (sumCoeff != 0) {
                    result.insertTerm(sumCoeff, current1.exponent);
                }
                current1 = current1.next;
                current2 = current2.next;
            }
        }

        // Append any remaining terms from poly1 or poly2
        while (current1 != null) {
            result.insertTerm(current1.coefficient, current1.exponent);
            current1 = current1.next;
        }
        while (current2 != null) {
            result.insertTerm(current2.coefficient, current2.exponent);
            current2 = current2.next;
        }

        return result;
    }

    // Function to multiply two polynomials
    public static PolynomialOperations3524 multiplyPolynomials(PolynomialOperations3524 poly1, PolynomialOperations3524 poly2) {
        PolynomialOperations3524 result = new PolynomialOperations3524();
        Node current1 = poly1.head;

        while (current1 != null) {
            Node current2 = poly2.head;
            while (current2 != null) {
                int productCoeff = current1.coefficient * current2.coefficient;
                int productExp = current1.exponent + current2.exponent;
                result.insertTerm(productCoeff, productExp);
                current2 = current2.next;
            }
            current1 = current1.next;
        }

        return result;
    }

    public static void main(String[] args) {
        // Code for getting the current date and time
        DateTimeFormatter dtf = DateTimeFormatter.ofPattern("yyyy/MM/dd HH:mm:ss");
        LocalDateTime now = LocalDateTime.now();
        System.out.println("2021503524  " + "Mugundh J B  " + dtf.format(now));

        Scanner in = new Scanner(System.in);
        PolynomialOperations3524 poly1 = new PolynomialOperations3524();
        PolynomialOperations3524 poly2 = new PolynomialOperations3524();

        // Input for the first polynomial
        System.out.print("Enter the number of terms in the first polynomial: ");
        int n1 = in.nextInt();
        System.out.println("Enter the terms for the first polynomial (like coeff, exp => ex : 5 2 , which means 5x^2) :");
        for (int i = 0; i < n1; i++) {
            int coef = in.nextInt();
            int exp = in.nextInt();
            poly1.insertTerm(coef, exp);
        }

        // Input for the second polynomial
        System.out.print("Enter the number of terms in the second polynomial: ");
        int n2 = in.nextInt();
        System.out.println("Enter the terms for the second polynomial (like coeff, exp => ex : 5 2 , which means 5x^2) :");
        for (int i = 0; i < n2; i++) {
            int coef = in.nextInt();
            int exp = in.nextInt();
            poly2.insertTerm(coef, exp);
        }

        // Perform polynomial addition
        PolynomialOperations3524 sum = addPolynomials(poly1, poly2);
        System.out.print("Sum of polynomials: ");
        sum.display();

        // Perform polynomial multiplication
        PolynomialOperations3524 product = multiplyPolynomials(poly1, poly2);
        System.out.print("Product of polynomials: ");
        product.display();

    }
}
