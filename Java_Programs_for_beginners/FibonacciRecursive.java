public class FibonacciRecursive {
  public static void main(String[] args) {
    System.out.println(fibRecursive(10));
  }
  
  public static int fibRecursive(int n) {
        if (n <= 0) {
            return 0;
        } else if (n <= 2) {
            return 1;
        }

        return fibRecursive(n - 1) + fibRecursive(n - 2);
    }
}
