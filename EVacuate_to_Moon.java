import java.util.*;

public class EVacuate_to_Moon {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        while (t-- > 0) {
            int n, m, h;
            n = sc.nextInt();
            m = sc.nextInt();
            h = sc.nextInt();
            int car[] = new int[n];
            int power[] = new int[m];
            for (int i = 0; i < n; i++) {
                car[i] = sc.nextInt();
            }
            for (int i = 0; i < m; i++) {
                power[i] = sc.nextInt();
            }
            Arrays.sort(car);
            int temp = 0;
            for (int i = 0; i < car.length; i++) {
                for (int j = i + 1; j < car.length; j++) {
                    if (car[i] < car[j]) {
                        temp = car[i];
                        car[i] = car[j];
                        car[j] = temp;
                    }
                }
            }
            Arrays.sort(power);
            int temp1=0;
            for (int i = 0; i < power.length; i++) {
                for (int j = i + 1; j < power.length; j++) {
                    if (power[i] < power[j]) {
                        temp1 = power[i];
                        power[i] = power[j];
                        power[j] = temp1;
                    }
                }
            }
            int sum=0;
            for(int i=0;i<Math.min(m,n);i++)
            {
                sum+=Math.min(car[i],power[i]*h);
            }
            System.out.println(sum);
        }
    }
}
