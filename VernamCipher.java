import java.util.Scanner;
public class VernamCipher {
    public static String vc(String pt, String k) {
        if (pt.length() != k.length()) {
            throw new IllegalArgumentException("Key must be the same length as the plaintext.");
        }
        StringBuilder ct = new StringBuilder();
        for (int i = 0; i < pt.length(); i++) {
            ct.append((char) (pt.charAt(i) ^ k.charAt(i)));
        }
        return ct.toString();
    }
    public static String vernamDecipher(String ct, String k) {
        if (ct.length() != k.length()) {
            throw new IllegalArgumentException("Key must be the same length as the ciphertext.");
        }
        StringBuilder pt = new StringBuilder();
        for (int i = 0; i < ct.length(); i++) {
            pt.append((char) (ct.charAt(i) ^ k.charAt(i)));
        }
        return pt.toString();
    }
    public static void bruteForceDecrypt(String ct, String k) {
        char[] possibleKeys = {'A', 'B', 'C', 'D', 'E'};
        for (char key : possibleKeys) {
            StringBuilder decrypted = new StringBuilder();
            for (int i = 0; i < ct.length(); i++) {
                decrypted.append((char) (ct.charAt(i) ^ key));
            }
            System.out.println("Attempt with key '" + key + "': " + decrypted);
        }
    }
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter plaintext (pt): ");
        String pt = scanner.nextLine();
        System.out.print("Enter key (k, must be the same length as the plaintext): ");
        String k = scanner.nextLine();
        try {
            String ct = vc(pt, k);
            System.out.println("Ciphertext (ct): " + ct);
            System.out.println("Decrypted plaintext (pt): " + vernamDecipher(ct, k));
        } catch (IllegalArgumentException e) {
            System.out.println(e.getMessage());
        }
        System.out.println("\nBrute-force Decrypt Attempts:");
        bruteForceDecrypt(pt, k);
    }
}
