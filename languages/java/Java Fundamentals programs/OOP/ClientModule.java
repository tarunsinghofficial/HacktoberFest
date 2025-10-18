public class ClientModule
{
    public static void main(String args[])
    {
        Employee employee = new Employee(1, "stanley", "ict", true);
        hireEmployee(employee);
        printEmployeeReport(employee, FormatType.XML);
    }

    public static void hireEmployee(Employee employee)
    {
        EmployeeDAO employeeDao = new EmployeeDAO();
        employeeDao.saveEmployee(employee);  
    }

    public static void terminateEmployee(Employee employee)
    {
        EmployeeDAO employeeDao = new EmployeeDAO();
        employeeDao.deleteEmployee(employee);
    }

    public static void printEmployeeReport(Employee employee, FormatType formatType)
    {
        EmployeeReportFormatter formatter = new EmployeeReportFormatter(employee, formatType);
        System.out.println(formatter.getFormattedEmployee());
    }
}