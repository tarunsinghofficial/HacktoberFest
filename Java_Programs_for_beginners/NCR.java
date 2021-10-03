import java.util.Scanner;

class NCR {
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        System.out.println("Enter number of times");
        int times = Integer.parseInt(s.nextLine());
        for (int i = 0; i < times; i++) {
            System.out.println("enter length");
            int l = Integer.parseInt(s.nextLine());
            System.out.println("enter string");
            String str = s.nextLine();
            int a = 0;
            int b = 0;
            boolean chance = true;
            StringBuffer sb = new StringBuffer(str);

            while (sb.length() > 0) {

                char c = sb.charAt(0);
                if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
                    sb.replace(0, 1, "z");

                } else {
                    sb.deleteCharAt(0);
                }
                if (chance)
                    a++;
                else
                    b++;
                chance = !chance;
            }
            if (a > b)
                System.out.println("A");
            else if (b > a)
                System.out.println("B");
            else
                System.out.println("D");
        }

    }
}
