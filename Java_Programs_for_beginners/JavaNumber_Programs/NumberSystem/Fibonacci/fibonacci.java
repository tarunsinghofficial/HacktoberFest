
public class fibonacci {
    public static void main(String args []){
        int a,b,c=0,n=3;
        a=0;b=1;
        System.out.println(a);
        System.out.println(b);
        while(n<=10){
            c=a+b;
            System.out.println(c);
            a=b;
            b=c;
            n++;
        }
    }
}
