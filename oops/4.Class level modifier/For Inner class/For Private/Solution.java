import pack4.Test;

public class Solution{
	public static void main(String[] args) {
		Test.Private.m1();
	}
}

// Private class cant be acessed from out side classes

/**
D:\USER_D\desktop\some file\java\oops\4.Class level modifier\For Inner class\For Private>javac Solution.java
Solution.java:6: error: Test.Private has private access in Test
                t.Private.m1();
                 ^
1 error
*/