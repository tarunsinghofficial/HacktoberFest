//C# code to generate bill
/* Generate Bill Deatails
consider the following prices:
rs.200/pizza
rs.40/puffs
rs.120/pepsi
Generate a bill.
the bill details must include the total cost pizzas,puffs and pepsis.
Display the GST and CESS amount. GST is 12% and CESS is 5% of the total price. */

//solution:

using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ProgFundamentals2  
{
    public class Program     
    {
        public static void Main(string[] args)    
        {
           
			int no_pizzas, no_puffs, no_pepsi;
			int cost_pizza, cost_puffs, cost_pepsi;
			int totalAmount;
			double GST, CESS;
			
			int costPerPizza = 200, costPerPuff = 40, costPerPepsi = 120;
			
            Console.Write("Enter the number of pizzas bought : ");
            no_pizzas = Convert.ToInt32(Console.ReadLine());
            
            Console.Write("Enter the number of puffs bought : ");
            puffs = Convert.ToInt32(Console.ReadLine());
            
            Console.Write("Enter the number of pepsi bought : ");
            pepsi = Convert.ToInt32(Console.ReadLine());
            
            cost_pizza = costPerPizza * no_pizzas;
			cost_puffs = costPerPuff * no_puffs;
			cost_pepsi = costPerPepsi * no_pepsi;
			
			totalAmount = cost_pizza + cost_puffs + cost_pepsi;
            
			GST = totalAmount * 0.12;
			CESS = totalAmount * 0.05;
			
            Console.WriteLine("Bill Details");
            Console.WriteLine("Cost of Pizzas : " + cost_pizza);
            Console.WriteLine("Cost of Puffs : " + cost_puffs);
            Console.WriteLine("Cost of Pepsis : " + cost_pepsi);
            Console.WriteLine("GST 12% : " + GST);
            Console.WriteLine("CESS 5% : " + CESS);
            Console.WriteLine("Total Price : " + totalAmount);
        }
    }
}
