
import java.io.*;
import java.util.*;

class COCOMO {
	public static void main (String[] args) {
		double efforts=0, developmentTime=0;
		Scanner sc=new Scanner(System.in);
		int KLOC=sc.nextInt();
		//Organic Mode
		efforts=2.4*Math.pow(KLOC,1.05);
		developmentTime=2.5*Math.pow(efforts,0.38);
		System.out.println("Organic Mode");
		System.out.println("Efforts: "+efforts+" Person Months\nDevelopment Time: "+developmentTime+" Months");
		System.out.println();
		//Semidetached Mode
		efforts=3.0*Math.pow(KLOC,1.12);
		developmentTime=2.5*Math.pow(efforts,0.35);
	    System.out.println("Semidetached Mode");
		System.out.println("Efforts: "+efforts+" Person Months\nDevelopment Time: "+developmentTime+" Months");
	    System.out.println();
	    //Embedded Mode 
	    efforts=3.6*Math.pow(KLOC,1.20);
	    developmentTime=2.5*Math.pow(efforts,0.32);
	    System.out.println("Embedded Mode ");
	    System.out.println("Efforts: "+efforts+" Person Months\nDevelopment Time: "+developmentTime+" Months");
	}
}
