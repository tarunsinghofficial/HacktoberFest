import java.util.Scanner;

public class perfect{
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);        
        int range, num, sum=0;

        System.out.println("Enter Range To Find Perfect Numbers:");
        range=input.nextInt();

    System.out.println("Perfect Numbers Up To " + range + ":");
     for(int i = 6; i <= range; i++){
        sum=0; 
        num=i;
            for (int x = 1; x < num; x++) {
                if ((num % x) == 0) {
                    sum += x;
                }
            }
            
            if (sum == num) {
                System.out.println(num);
            }
     }
    }
}