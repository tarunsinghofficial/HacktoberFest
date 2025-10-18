public class EmployeeDAO
{
    public void saveEmployee(Employee employee)
    {
        System.out.println("Saved employee to database: " + employee);
    }

    public void deleteEmployee(Employee employee)
    {
        System.out.println("Deleted employee from database: " + employee);
    }
}