/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
//package recursion;

/**
 *
 * @author Zohaib Hassan Soomro
 */
//program to find nth term of fabonacci series: 0 1 1 2 3 5 8 13 21 34...
public class FabonacciRecursion {
    public static void main(String[] args) {
    	/*for (int i=0;i<=10;i++) {
        	System.out.println("fabonacci("+i+") : "+fabonacci(i));
        }*/
        long start=System.currentTimeMillis();
        fabonacci(100);
        long end=System.currentTimeMillis();
        System.out.println("Total Time: "+(end-start)+" mili-seconds.");
    }
    public static long fabonacci(int n){
    	if(n<1)  return 0;
    	if(n<3)  return 1;
    	return fabonacci(n-1)+fabonacci(n-2);
    }
}
