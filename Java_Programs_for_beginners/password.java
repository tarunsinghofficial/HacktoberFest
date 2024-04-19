import java.util.*;
class password
{
    public static void main()
    {
        Scanner in=new Scanner(System.in);
        System.out.println("Enter length: ");
        int l=in.nextInt();
        System.out.println("Generating password : ");
        System.out.print("Your new password is : ");
        String Capital = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        String Small = "abcdefghijklmnopqrstuvwxyz";
        String num = "0123456789";
        String s = "!@.?*$#";
        String pass = Capital + Small +num + s;
        Random r = new Random();
        char[] password = new char[l];
        for (int i = 0; i < l; i++)
        {
            password[i] =pass.charAt(r.nextInt(pass.length()));
        }
        System.out.println(password);
    }
}