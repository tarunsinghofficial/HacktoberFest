public class Employee
{
    public void handleCustomer(Customer cust, boolean finance, Vehicle vehicle)
    {
        if (finance == true)
        {
            double loanAmount = vehicle.getPrice() - cust.getCashOnHand();
            runCreditHistory(cust, loanAmount);
        }
        else if (vehicle.getPrice() <= cust.getCashOnHand())
        {
            processTransaction(cust, vehicle);
        }
        else
        {
            System.out.println("Customer is broke asf!");
        }
    }

    public void runCreditHistory(Customer cust, double loanAmount)
    {
        System.out.println("Running credit history for customer...");
        System.out.println("Customer approved for purchase!");
    }

    public void processTransaction(Customer cust, Vehicle vehicle)
    {
        System.out.println("Customer has purchased vehicle: " +
                        vehicle + " for $" + vehicle.getPrice());
    }
}