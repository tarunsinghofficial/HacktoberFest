import java.io.*;
import java.util.*;
class LeftRotateArray{
	public static void main(String args[]){
	int n;
	Scanner sc=new Scanner(System.in);
	System.out.println("Enter the value of N");
	n=sc.nextInt();
	int arr[]=new int[n];
	System.out.println("Enter The Array Elements");
	for(int i=0;i<n;i++){
		arr[i]=sc.nextInt();
	}
	System.out.println("The array list before rotation");
	for(int j=0;j<n;j++){
		System.out.print(arr[j]+"\t");
	}
	System.out.println("The array list after rotation");
		int first=arr[0];
	for(int k=0;k<n;k++){
		if(k==(n-1)){
		arr[n-1]=first;
		}
		else{
		arr[k]=arr[k+1];
		}
	}
	for(int l=0;l<n;l++){
	System.out.print(arr[l]+"\t");
	}
	}
}

		