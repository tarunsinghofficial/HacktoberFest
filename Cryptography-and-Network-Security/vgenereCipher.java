package com.company;

import java.util.Scanner;

public class vgenereCipher {
    public static String generateKey(String str,String key){
        int x=str.length();
        for (int i=0; ;i++){
            if (x==i) {
                i = 0;
            }
            if (key.length()==str.length()) {
                break;
            }
            key+=(key.charAt(i));
        }
        return key;
    }
    static String cipherText(String str,String key){
        String cipherText="";
        for(int i=0;i<str.length();i++){
            int x = (str.charAt(i) + key.charAt(i)) %26;
            x += 'A';
            cipherText += (char)(x);
        }
        return cipherText;
    }
     static String plainText(String cipherText,String key){
        String plainText="";
        for (int i=0;i<cipherText.length() && i<key.length();i++){
            int x=(cipherText.charAt(i)-key.charAt(i)+26) %26;
            x+='A';
            plainText+=(char)x;
        }
        return plainText;
    }

    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        String str1=sc.nextLine();
        System.out.println("Enter the plainText "+str1);
        String key1=sc.nextLine();
        System.out.println("Enter the key "+key1);
        String cipherText=cipherText(str1,key1);
        System.out.println("cipher text are "+cipherText);
        String plaintext=plainText(cipherText,key1);
        System.out.println("PlainText are "+plaintext);
    }
}
