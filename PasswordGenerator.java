import java.util.Random;
public class PasswordGenerator {
    public static void main (String[] args){
        int length = 10;
        System.out.println(generatePswd(length));
    }
    static char[] generatePswd(int len)
    {
        System.out.println("This is Your Password:");
        String alphabe = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        String alphabeLowercase = "abcdefghijklmnopqrstuvwxyz";
        String nums = "0123456789";
        String symbols = "!@#$%^&*_=+-/€.?<>)";
        String passSymbols = alphabe + alphabeLowercase + nums + symbols;
        Random rnd = new Random();
        char[] password = new char[len];
        int index = 0;
        for (int i = 0; i < len; i++) 
        {
            password[i] = passSymbols.charAt(rnd.nextInt(passSymbols.length()));  
        }
        return password;
    }
}