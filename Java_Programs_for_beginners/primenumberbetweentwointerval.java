import java.util.Scanner;

class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the starting number");
        int s = sc.nextInt();
        System.out.println("Enter the starting number");
        int e = sc.nextInt();
        int i = 0, j = 0, flag = 0;
        ;
        System.out.println("prime number between" + ' ' + s + ' ' + e);
        for (i = s; i <= e; i++) {
            flag = 1;
            if (i == 1 || i == 0) {
                continue;
            }
            for (j = 2; j <= i / 2; j++) {
                if (i % j == 0) {
                    flag = 0;
                }
            }
            if (flag == 1) {
                System.out.println(i);
            }
        }
    }
}
