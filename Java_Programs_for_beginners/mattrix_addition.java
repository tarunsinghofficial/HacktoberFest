import java.util.Scanner;

public class mattrix_addition {

 public static void main(String[] args) {
		 
		 Scanner sc = new Scanner(System.in);
		 
		 int ar[][]= new int[3][3];
		 int ar1[][]= new int[3][3];
		 int ar3[][]= new int[3][3];
		 int i, j, sum = 0;
		 
		 System.out.println("enter array : ");
		 for (i = 0 ; i < 3; i++) {
			 
			 for (j=0 ; j< 3;j++ )
			 {
				 
				 ar[i][j] = sc.nextInt();
			 }
			 
		 }
		 
		 System.out.println("array : ");
		 for(i = 0 ; i <3; i++) {
			 for(j = 0 ; j<3; j++) {
				 
				 System.out.print(ar[i][j] + " ");
				 				 
			 }
			 
			 System.out.println();
		 }
		 
		 System.out.println("enter 2nd array : ");
		 for (i = 0 ; i < 3; i++) {
			 
			 for (j=0 ; j< 3;j++ )
			 {
				 
				 ar1[i][j] = sc.nextInt();
			 }
			 
 }
		
		 System.out.println("array : ");
		 for(i = 0 ; i <3; i++) {
			 for(j = 0 ; j<3; j++) {
				 
				 System.out.print(ar1[i][j] + " ");
				 		 
			 }
			 
			 System.out.println();
		 }
		 
		 System.out.println("addition array : ");
		 for (i = 0 ; i < 3; i++) {
			 
			 for (j=0 ; j< 3;j++ )
			 {
				 
				 ar3[i][j] = ar[i][j] + ar1[i][j];
				 
				 System.out.print(ar3[i][j] + " ");
			 }
			 System.out.println();
		 }
		 
 }
 
}
