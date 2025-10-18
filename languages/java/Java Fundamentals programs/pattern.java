public class pattern{
    public static void main(String[] args) {
        
        for(int x=1;x<=4;x++){
            for(int y=x;y<=x*x;y+=x){
                System.out.print(y + " ");
            }
           System.out.println();
        }
        int m=2;
        for (int x = 5; x <= 7; x++) {
            for (int y = 1; y <= x-m; y++) {
                System.out.print(y*x + " ");
            }
            m*=2;
            System.out.println();
        }
    }
}