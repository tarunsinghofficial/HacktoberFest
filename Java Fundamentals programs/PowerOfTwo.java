import java.util.Scanner;
public class PowerOf2{
	static boolean powerOf2(int n){
		if(n==0){                                //since we are getting exception here so exclude this condition.
			return false;                           
		}                                          
		 return ((n)&(n-1))==0;
	}
	public static void main(String[] args) {     
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();        //8 ,10,16
		System.out.println(powerOf2(n));
	}
}
