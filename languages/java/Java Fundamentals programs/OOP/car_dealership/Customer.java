public class Customer
{
    private String name;
    private String address;
    private double cashOnHand;

    public void setName(String name)
    {
        this.name = name;
    }

    public String getName()
    {
        return this.name;
    }

    public void setAddress(String address)
    {
        this.address = address;
    }

    public String getAddress()
    {
        return this.address;
    }

    public void setCashOnHand(double cashOnHand)
    {
        this.cashOnHand = cashOnHand;
    }

    public double getCashOnHand()
    {
        return this.cashOnHand;
    }

    public void purchaseCar(Vehicle vehicle, Employee emp, boolean finance)
    {
        emp.handleCustomer(this, finance, vehicle);   
    }

}