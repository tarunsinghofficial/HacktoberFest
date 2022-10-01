package com.company;

import java.util.Locale;
import java.util.Scanner;

public class vernamCipher{

    public static String stringEncryption(String text,String key) {
        String cipherText = "";
        int cipher[] = new int[key.length()];
        for (int i = 0; i < key.length(); i++) {
            cipher[i] = text.charAt(i) - 'A' + key.charAt(i) - 'A';
        }
        for(int i=0;i<key.length();i++){
            if(key.length()>26){
                cipher[i]=cipher[i]-26;
            }
        }
        for(int i=0;i<key.length();i++){
            int x=cipher[i]+'A';
            cipherText+=(char)x;
        }
        return cipherText;
    }
    public static String stringDecryption(String s,String key){
        String plainText="";
        int plain[]=new int[key.length()];
        for (int i = 0; i < key.length(); i++) {
            plain[i] = s.charAt(i) - 'A' - (key.charAt(i) - 'A');
        }
        for(int i=0;i<key.length();i++){
            if(key.length()<0){
                plain[i]=plain[i]+26;
            }
        }
        for(int i=0;i<key.length();i++){
            int x=plain[i]+'A';
            plainText+=(char)x;
        }
        return plainText;
    }
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        String str=sc.nextLine();
        System.out.println("Enter the plainText"+str);
        String str2=sc.nextLine();
        System.out.println("Enter the key"+str2);

        String encryptedText = stringEncryption(str.toUpperCase(), str2.toUpperCase());
        System.out.println("cipher text are " + encryptedText);

        System.out.println("Message"+stringDecryption(encryptedText,str2.toUpperCase()));

    }
}