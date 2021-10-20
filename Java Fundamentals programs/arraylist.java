import java.util.Scanner;
import java.util.ArrayList;

public class arraylist{
    public static void main(String[] args) {
        Scanner input=new Scanner(System.in);
        ArrayList<String> names =new ArrayList<String>();
        
        System.out.println("Enter 5 names:");
        for (int i=0;i<5;i++){
            names.add(i, input.next());
        }

        for(String item:names){
            System.out.println(item);
        }


    }
}