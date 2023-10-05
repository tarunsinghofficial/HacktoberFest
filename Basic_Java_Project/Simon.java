package Basic_Java_Project;
import java.util.*;

public class Simon {

    public static void level1() {
        Scanner s=new Scanner(System.in);
        ArrayList<Integer> temp=new ArrayList<>();
        boolean fool=true;
        while (fool) {
            System.out.println("Enter a Number");
            temp.add(s.nextInt());
               int l=temp.size();
               System.out.println("Verify Sequence");
            for (int i = 0; i < l; i++) {
                int n=s.nextInt();
                if (n==temp.get(i)) {
                    continue;                }
                else{
                    fool=false;
                    System.out.println("Game Over, Wrong Sequence");
                    break;
                }
            }
        }
    }
    public static void level2() {
        Scanner s=new Scanner(System.in);
        ArrayList<Integer> temp=new ArrayList<>();
        boolean fool=true;
        while (fool) {
            System.out.println("Enter a Number");
            temp.add(s.nextInt());
               int l=temp.size();
               System.out.println("Verify Sequence in reverse");
            for (int i = 0; i < l; i++) {
                int n=s.nextInt();
                if (n==temp.get(l-i-1)) {
                    continue;                }
                else{
                    fool=false;
                    System.out.println("Game Over, Wrong Sequence");
                    break;
                }
            }
        }
    }


    public static void main(String[] args) {
        Scanner s=new Scanner(System.in);

        System.out.println("Choose Simon Level 1 or 2");
         int n=s.nextInt();
         if(n==1){
            level1();
         }
         else if(n==2){
            level2();
         }
         else{
            System.out.println("Invalid level");
         }
        s.close();

    }
}