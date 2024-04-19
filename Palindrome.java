class Main {
  public static void main(String[] args) {
    
    int number = 7865, reversednumber = 0, remainder;
    
    int originalnumber = number;
    
    while (number != 0) {
      remainder = number % 10;
      reversednumber = reversednumber * 10 + remainder;
      number /= 10;
    }
    
    if (originalnumber == reversednumber) {
      System.out.println(originalnumber + " is Palindrome number.");
    }
    else {
      System.out.println(originalnumber + " is not Palindrome number.");
    }
  }
}
