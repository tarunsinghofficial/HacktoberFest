package com.company;
import java.util.*;
import java.io.*;

class main{
    public static void main(String []argh)
    {
        Scanner in = new Scanner(System.in);
        int n=in.nextInt();
        in.nextLine();
        HashMap<String,Integer> h = new HashMap<>();
        for(int i=0;i<n;i++)
        {
            String name=in.nextLine();
            int phone=in.nextInt();
            h.put(name,phone);
            in.nextLine();
        }
        while(in.hasNext())
        {
            String s=in.nextLine();
            if(h.containsKey(s)){
                System.out.println(s+"="+h.get(s));
            }else{
                System.out.println("Not found");
            }
        }
    }
}

