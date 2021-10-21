/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package recursion;

/**
 *
 * @author Zohaib Hassan Soomro
 */
public class FactorialRecursion {
    public static void main(String[] args){
        for (int i=1;i<=10;i++) {
        	System.out.println("factorial("+i+") : "+factorial(i));
        }
    }
    public static long factorial(int n){
    	if(n<2) return 1;
    	return n*factorial(n-1);
    }
}
