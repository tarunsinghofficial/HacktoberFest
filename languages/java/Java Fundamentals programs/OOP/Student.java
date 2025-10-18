public class Student extends Person
{
    private String studentID;
    private int semester;
    private String major;
    private String dept;

    public Student()
    {
        super("Keith", "Charedzera", 19, "whatever");
        this.studentID = "H190232Q";
        this.semester = 3;
        this.major = "Computer Science";
        this.dept = "SIST";
    }

    public static void main(String args[])
    {
        Student student1 = new Student();
        System.out.println(student1.name);
    }

}