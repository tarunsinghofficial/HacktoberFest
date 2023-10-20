
public class reversenumber {
    public static void main (String args[]){
        int n = 108877;
        while (n>0){
            int ld = n%10;
            System.out.print(ld);
            n = n/10;
        }
        System.out.println();
    }
    
}
