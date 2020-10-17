import java.util.Scanner;
public class JavaExample {
    static int fact(int num) {
	int factorial;

	for(factorial = 1; num > 1; num--){
		factorial *= num;
	}
	return factorial;
    }
    static int ncr(int n,int r) {
	return fact(n) / ( fact(n-r) * fact(r) );
    }
    public static void main(String args[]){
	int rows, i, j;

	//getting number of rows from user
	System.out.println("Enter number of rows:");
	Scanner scanner = new Scanner(System.in);
	rows = scanner.nextInt();
	scanner.close();

	System.out.println("Pascal Triangle:");
	for(i = 0; i < rows; i++) {
		for(j = 0; j < rows-i; j++){
			System.out.print(" ");
		}
		for(j = 0; j <= i; j++){
			System.out.print(" "+ncr(i, j));
		}
		System.out.println();
 	}
    }
}
