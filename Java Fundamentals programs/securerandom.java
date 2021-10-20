import java.security.SecureRandom;

public class random{
    public static void main(String[] args) {
        
        SecureRandom randomNum = new SecureRandom();
        
        for (int i=0;i<=5;i++){
            System.out.println(randomNum.nextInt(10));
        }
    }
}