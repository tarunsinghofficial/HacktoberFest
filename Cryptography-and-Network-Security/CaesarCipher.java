package com.company;


import java.util.Locale;
import java.util.Scanner;

public class CaesarCipher {

    public static final String ALPHABET="abcdefghijklmnopqrstuvwxyz";
    public static String encrypt(String plaintext,int shiftkey){
          plaintext=plaintext.toLowerCase();
          String cipherText="";
          for (int i=0;i<plaintext.length();i++){
              int charPosition=ALPHABET.indexOf(plaintext.charAt(i));
              int keyval=(shiftkey+charPosition)%26;
              char replaceVal=ALPHABET.charAt(keyval);
              cipherText+=replaceVal;
          }
          return cipherText;
    }
    public static String decrypt(String chiperText,int shifkey){
        chiperText=chiperText.toLowerCase();
        String plaintext="";
        for(int i=0;i<chiperText.length();i++){
            int charPosition=ALPHABET.indexOf(chiperText.charAt(i));
            int keyval=(charPosition-shifkey)%26;
            if(keyval<0){
                keyval=ALPHABET.length()+keyval;
            }
            char replaceVal=ALPHABET.charAt(keyval);
            plaintext+=replaceVal;
        }
        return plaintext;
    }

    public static void main(String[] args) {
//        Encrypt
        String message;
        System.out.println("Enter the CipherText :");
        Scanner sc=new Scanner(System.in);
        message=sc.next();
        System.out.println(encrypt(message,3));

//        Decrypt
        System.out.println(decrypt(encrypt(message,3),3));
    }
}