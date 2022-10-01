package com.company;

import java.util.Scanner;

import static com.company.GCD.gcd;

public class eulersTotient {
    public static int GCD(int a,int b){
        if (a==0){
            return b;
        }
        return gcd(b%a,b);
    }
    
    public static int phi(int n){
        int results=1;
        for(int i=2;i<n;i++){
            if(GCD(i,n)==1){
                results++;
            }
        }
        return results;
    }
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        System.out.println(phi(n));
    }
}
