import java.util.Scanner;  
public class DiamondPattern  
{  
public static void main(String[] args) {
    int row, i, j, space = 1;
    System.out.print("Enter the number of rows you want to print: ");
    Scanner sc = new Scanner(System.in);
    row = sc.nextInt();
    for (int i = 0; i < row; i++) {
      for (int j = i; j < row - 1; j++) {
        System.out.print(" ");
      }
      for (int k = 0; k <= i; k++) {
        System.out.print("* ");
      }
      System.out.println();
    }

    row--;

    for (int a = 0; a < row; a++) {
      for (int b = 0; b <= a; b++) {
        System.out.print(" ");
      }
      for (int c = a; c <= row - 1; c++) {
        System.out.print("* ");
      }
      System.out.println();
    }
  }
}
}  
