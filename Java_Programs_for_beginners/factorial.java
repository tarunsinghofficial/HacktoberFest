import java.util.*;

class factorial {
    public static void main(String[] args) {
        int n, ans = 1;
        Scanner obj = new Scanner(System.in);
        System.out.println("Enter Number: ");
        n = obj.nextInt();

        for (int i = n; i >= 1; i--) {
            ans = ans * i;
        }
        System.out.println(" " + ans);
    }
}  