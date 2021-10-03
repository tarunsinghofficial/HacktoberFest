package Cipher;

import java.util.Scanner;

/**
 * It has 7 cipher conversion algorithm.
 * Both encoding and decoding feature is added.
 * The actual input message can be retrieved after decoding in each algorithm.
 *
 * @author Jetty53
 */

public class MAIN {

    public static void main(String[] args) {

        Scanner scanner = new Scanner(System.in);
        int choice = -1;

        System.out.println("Press <1> to ADFGVX cipher");
        System.out.println("Press <2> to AFFINE cipher");
        System.out.println("Press <3> to ATBASH cipher");
        System.out.println("Press <4> to BEAUFORT cipher");
        System.out.println("Press <5> to CAESER cipher");
        System.out.println("Press <6> to RAIL-FENCE cipher");
        System.out.println("Press <7> to ROT13 cipher");
        System.out.println("Press <0> to exit");

        while (choice != 0) {

            System.out.println("Enter your choice: ");
            choice = scanner.nextInt();

            switch (choice) {
                case 0:
                    break;
                case 1:
                    ADFGVX();
                    break;
                case 2:
                    AFFINE();
                    break;
                case 3:
                    ATBASH();
                    break;
                case 4:
                    BEAUFORT();
                    break;
                case 5:
                    CAESER();
                    break;
                case 6:
                    RAILFENCE();
                    break;
                case 7:
                    ROT13();
                    break;
                default:
                    System.out.println("Invalid Input");
                    break;
            }
        }

    }

    private static void ADFGVX() {
        ADFGVX adfgvx = new ADFGVX();
        Scanner scanner = new Scanner(System.in);
        System.out.println("Enter the plain text: ");
        String inputText = scanner.nextLine();
        System.out.println("Enter the matrix pattern: ");
        String matrixPat = scanner.nextLine();
        System.out.println("Enter the key text: ");
        String keyText = scanner.nextLine();

        String encode = adfgvx.encodeProcedureADFGVX(inputText, matrixPat, keyText);
        String decode = adfgvx.decodeProcedureADFGVX(encode, matrixPat, keyText);

        System.out.println("The encoded String is: " + encode);
        System.out.println("The decoded String is: " + decode);

    }

    private static void AFFINE() {
        AFFINE affine = new AFFINE();
        Scanner scanner = new Scanner(System.in);
        String encode = null;
        String decode;
        System.out.println("Enter the plain text: ");
        String inputText = scanner.nextLine();
        System.out.println("Enter the A key number ");
        int keyA = scanner.nextInt();
        System.out.println("Enter the B key number ");
        int keyB = scanner.nextInt();

        if ((GCD(keyA, 26) == 1) & ((1 <= keyA) & (keyA <= 25)) & ((0 <= keyB) & (keyB <= 25))) {
            encode = affine.encodeProcedureAFFINE(inputText, keyA, keyB);
            decode = affine.decodeProcedureAFFINE(encode, keyA, keyB);

            System.out.println(encode);
            System.out.println(decode);
        } else {
            System.out.println("Sorry, invalid key input.");
        }

        assert encode != null;


    }

    private static void ATBASH() {
        ATBASH atbash = new ATBASH();
        Scanner scanner = new Scanner(System.in);
        System.out.println("Enter the plain text: ");
        String inputText = scanner.nextLine();

        String encode = atbash.encodeProcedureATBASH(inputText);
        String decode = atbash.decodeProcedureATBASH(encode);

        System.out.println("The encoded String is: " + encode);
        System.out.println("The decoded String is: " + decode);
    }

    private static void BEAUFORT() {

        BEAUFORT beaufort = new BEAUFORT();
        Scanner scanner = new Scanner(System.in);
        System.out.println("Enter the plain text: ");
        String inputText = scanner.nextLine();
        System.out.println("Enter the key: ");
        String keyText = scanner.nextLine();

        String encode = beaufort.encodeProcedureBEAUFORT(inputText, keyText);
        String decode = beaufort.decodeProcedureBEAUFORT(encode, keyText);

        System.out.println("The encoded String is: " + encode);
        System.out.println("The decoded String is: " + decode);


    }

    private static void CAESER() {

        CAESER caeser = new CAESER();
        Scanner scanner = new Scanner(System.in);
        System.out.println("Enter the plain text: ");
        String inputText = scanner.nextLine();
        System.out.println("Enter the offset number(0 - 25): ");
        int offsetInt = scanner.nextInt();

        String encode = caeser.encodeProcedureCASESER(inputText, offsetInt);
        String decode = caeser.decodeProcedureCASESER(encode, offsetInt);

        System.out.println("The encoded String is: " + encode);
        System.out.println("The decoded String is: " + decode);


    }

    private static void RAILFENCE() {
        RAILFENCE railfence = new RAILFENCE();
        Scanner scanner = new Scanner(System.in);
        System.out.println("Enter the plain text: ");
        String inputText = scanner.nextLine();
        System.out.println("Enter the key: ");
        int key = scanner.nextInt();

        String encode = railfence.encodeProcedureRAILFENCE(inputText, key);
        String decode = railfence.decodeProcedureRAILFENCE(encode, key);

        System.out.println("The encoded String is: " + encode);
        System.out.println("The decoded String is: " + decode);
    }

    private static void ROT13() {
        ROT13 rot13 = new ROT13();
        Scanner scanner = new Scanner(System.in);
        System.out.println("Enter the plain text: ");
        String inputText = scanner.nextLine();

        String encode = rot13.encodeDecodeProcedureROT13(inputText);
        String decode = rot13.encodeDecodeProcedureROT13(encode);

        System.out.println("The encoded String is: " + encode);
        System.out.println("The decoded String is: " + decode);
    }

    private static int GCD(int a, int b) {
        if (b != 0) {
            return GCD(b, a % b);
        } else {
            return a;
        }
    }


}
