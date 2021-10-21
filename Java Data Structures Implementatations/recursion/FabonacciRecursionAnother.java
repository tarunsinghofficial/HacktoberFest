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
public class FabonacciRecursionAnother {
    public static void main(String[] args){
    	long array[]= new long[12];
    	array[0]=0;
    	array[1]=1;
    	for (int i=2;i<array.length;i++) {
    		array[i]=array[i-1]+array[i-2];
    		System.out.println(array[i]);
    	}
    	System.out.println();
    	for (int i=13;i<=35;i++) {
    		System.out.println(fabonacciUsingArray(array,i));
    	}
    	
    }
    public static long fabonacciUsingArray(long array[],int n){
    	if(n<=array.length)
    		return array[n-1]+array[n-2];
    	return fabonacciUsingArray(array,n-1)+fabonacciUsingArray(array,n-2);
    }
}
