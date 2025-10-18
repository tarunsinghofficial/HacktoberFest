public class Employee
{
    private int id;
    private String name;
    private String dept;
    private boolean working;

    public Employee(int id, String name, String dept, boolean working)
    {
        super();
        this.id = id;
        this.name = name;
        this.dept = dept;
        this.working = working;
    }

    public String toString()
    {
        return "Employee [id = "+ id +", name = "+ name 
        +", department = "+ dept +", working = "+ working +"]";
    }
}