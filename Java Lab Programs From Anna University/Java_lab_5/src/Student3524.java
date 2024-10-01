import java.time.LocalDate;
import java.time.LocalTime;

class Student{
    int id;
    String name;
    // using this keyword
    Student(){
        this.id = 0;
        this.name = "Unknown";
    }
    // using this keyword
    Student(int id, String name){
        this.id = id;
        this.name = name;
    }

    void display() {
        System.out.println("Student ID: " + id);
        System.out.println("Student Name: " + name);
    }

    // Method to return an object
    static Student createStudent(int id, String name) {
        Student student = new Student(id, name);
        return student;
    }

    // Method to pass an object as an argument
    void updateStudent(Student newStudent) {
        this.id = newStudent.id;
        this.name = newStudent.name;
    }
}

public class Student3524 {
    public static void main(String[] args){
        System.out.println("2021503524 - Mugundh J B");
        System.out.println("Date: " + LocalDate.now() + " Time: " + LocalTime.now());

        // Using default constructor
        Student defaultStudent = new Student();
        System.out.println("Default Constructor Student:");
        defaultStudent.display();
        System.out.println();

        // Using parameterized constructor
        Student paramStudent = new Student(1, "Mugundh");
        System.out.println("Parameterized Constructor Student:");
        paramStudent.display();
        System.out.println();

        // Passing an object as an argument
        Student originalStudent = new Student(3, "Shivani");
        Student newStudent = new Student(4, "Shyamala");
        System.out.println("Original Student:");
        originalStudent.display();
        System.out.println("New Student:");
        newStudent.display();
        originalStudent.updateStudent(newStudent);

        System.out.println("\nAfter Updating Original Student:");
        originalStudent.display();
        System.out.println();

        // Returning an object
        Student returnedStudent = Student.createStudent(5, "Kiran");
        System.out.println("Returning Class Student:");
        returnedStudent.display();
    }
}
