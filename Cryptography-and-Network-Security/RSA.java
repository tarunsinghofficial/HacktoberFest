package com.company;

import java.math.BigDecimal;
import java.math.BigInteger;

public class RSA {

    public static void main(String[] args) {
        int p,q,n,z,d=0,e;
        int plainText=9;
        BigInteger msgback;
        double c;
        p=11;
        q=5;
        n=p*q;
        z=(p-1)*(q-1);
        System.out.println(z);
        for (e=2;e<z;e++){
            if (GCD(e,z)==1){
                break;
            }
        }
        for (int i=0;i<=9;i++){
            int x=1+(i*z);
            if(x%e==0){
                d=x/e;
                break;
            }
        }
        System.out.println(d);
        c=(Math.pow(plainText,e)%n);
        System.out.println(c);
        BigInteger N = BigInteger.valueOf(n);
        // converting float value of c to BigInteger
        BigInteger C = BigDecimal.valueOf(c).toBigInteger();
        msgback = (C.pow(d)).mod(N);
        System.out.println("Decrypted message is : "+ msgback);
    }
    public static int GCD(int e,int z){
        if (e==0){
            return z;
        }
        return GCD(z%e,e);
    }
}
