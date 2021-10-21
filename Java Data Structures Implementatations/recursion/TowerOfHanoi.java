/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
//package recursion;

/**
 *
 
 */
//program to find nth term of fabonacci series: 0 1 1 2 3 5 8 13 21 34...
public class TowerOfHanoi {
    public static void main(String[] args) {
    	towerOfHanoi(3,'A','B','C');
    }
    public static void towerOfHanoi(int noOfDisks,char from_rod,char to_rod,char auxilary_rod){
    	if(noOfDisks==1){
    		System.out.println("disk 1 from rod "+from_rod+" to rod "+to_rod+" is moved.");
    		return;	
    	}
    	towerOfHanoi(noOfDisks-1,from_rod,auxilary_rod,to_rod);
    	System.out.println("disk "+noOfDisks+" from rod "+from_rod+" to rod "+to_rod+" is moved.");
    	towerOfHanoi(noOfDisks-1,auxilary_rod,to_rod,from_rod);
    }
}
