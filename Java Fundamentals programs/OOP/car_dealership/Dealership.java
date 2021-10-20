public class Dealership
{
    public static void main(String args[])
    {
        Customer cust = new Customer();
        cust.setName("Stanley Brikkz");
        cust.setAddress("47 Vokola Road");
        cust.setCashOnHand(12000);

        Vehicle vehicle = new Vehicle();
        vehicle.setMake("Nissan");
        vehicle.setModel("X-Trail");
        vehicle.setPrice(6500);

        Employee emp = new Employee();

        cust.purchaseCar(vehicle, emp, true);
        //System.out.println(cust.getName());
    }
}