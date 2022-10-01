package com.company;

import java.util.Scanner;

import static com.company.GCD.gcd;

public class euclideanAlgorithm {
    public static int GCD(int a,int b){
        if (a==0){
            return b;
        }
        return gcd(b%a,a);
    }
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        int a=sc.nextInt();
        int b=sc.nextInt();
        System.out.println(GCD(a,b));
    }
}
