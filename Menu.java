// importing the class Scanner
 import java.util.Scanner;
 class Menu
 {
 public static void main(String argvs[])
 {
         int ch; // for storing user's choice
         double ar; // for storing area
        // variable for storing various dimensions of
        // different geometrical figure
         int length, breadth, height, diagonal1, diagonal2;
         int side;
         int radius;
         Scanner sc = new Scanner(System.in); // creating object of Scanner class
          // displaying the menu
          System.out.println("1: Right Angle Triangle");
          System.out.println("2: Area of Equilateral Triangle");
          System.out.println("3: Area of Square");
          System.out.println("4: Area of Rectangle");
          System.out.println("5: Area of Circle");
          System.out.println("6: Area of Rhombus");
          System.out.println("7: Program termination");
         lp : while(true) // labeling the while loop
         {
             System.out.print("Make your choice: ");  
             ch = sc.nextInt(); // reading user's choice
              switch (ch)
              {
                case 1: // for Right Angled Triangle
                 System.out.print("Enter the height of Right Angle Triangle \n");
                 height = sc.nextInt();
                 System.out.print("Enter the base of Right Angle Triangle \n");
                 breadth = sc.nextInt();
                 ar = (height * breadth)/2;
                 System.out.println("Area of the Right Angle Triangle is " + ar + "\n\n");
                 break;
                case 2:               
                 System.out.print("Enter the side of an Equilateral Triangle \n");
                 side = sc.nextInt();
                 ar=(side * side * Math.sqrt(3)) / 4;
                 System.out.println("Area of the Equilateral Triangle is " + ar + "\n\n");
                 break;
                case 3:
                 System.out.print("Enter the side of a Square \n");
                 side = sc.nextInt();
                 ar = side * side;
                 System.out.println("Area of the Square is "+ ar + "\n\n");
                 break;
                case 4:
                 System.out.print("Enter the length of a Rectangle \n");
                 length = sc.nextInt();
                 System.out.print("Enter the breadth of the Rectangle \n");
                 breadth = sc.nextInt();
                 ar = length * breadth;
                 System.out.println("Area of the Rectangle is " + ar + "\n\n");
                 break;
                case 5:
                 System.out.print("Enter the radius of a Circle \n");
                 radius = sc.nextInt();
                 ar = radius * radius * 22 / 7;
                 System.out.println("Area of the Circle is " + ar + "\n\n");
                 break;
                case 6:
                 System.out.print("Enter the first diagonal of a Rhombus \n");
                 diagonal1 = sc.nextInt();
                 System.out.print("Enter the second diagonal of the Rhombus \n");
                 diagonal2 = sc.nextInt();
                 ar = diagonal1 * diagonal2 * 1 / 2;
                 System.out.println("Area of the Rhombus is " + ar + "\n\n");
                 break;
                case 7:
                 // exiting from the switch-case as well as from the while loop using its label lp
                 break lp; 
                default:
                 System.out.println("Invalid choice! Please make a valid choice. \n\n");
               }
             }
 }
 } 
