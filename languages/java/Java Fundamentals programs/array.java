import java.util.Scanner;

public class array{
    public static void main(String[] args) {
        Scanner input =  new Scanner(System.in);
        String[] myArray=new String[5];
        String name;
        //System.out.println(myArray.length);

        for (int i=0;i<=myArray.length-1;i++){
            name=input.next();
            myArray[i]=name;
        }
        for (int i=0;i<=myArray.length-1;i++){
            System.out.println(myArray[i]);
        }
    }
}