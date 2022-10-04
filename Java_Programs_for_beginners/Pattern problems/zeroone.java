package com.diksha;

public class zeroone {
    public static void main(String[] args) {
        int n=5;
        for (int i = 0; i <=n ; i++) {
            for (int j = 1; j <=i; j++) {
                int sum =i+j;
                if (sum % 2 ==0){
                    System.out.print("1");
                }
                else{
                    System.out.print("0");
                }

            } System.out.println(" ");

        }
    }
}
