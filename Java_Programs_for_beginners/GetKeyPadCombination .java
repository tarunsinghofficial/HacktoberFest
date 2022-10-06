
import java.util.*;

public class GetKeyPadCombination{
	static String []codes={".;","abc","def","ghi","jkl","mno","pqrs","tu","vwx","yz"};
	public static void main(String[] args) {
		Scanner sc=new Scanner (System.in);
		String str=sc.nextLine();
		ArrayList<String>al=getKPC(str);
		System.out.println(al);
		}
	public static ArrayList<String> getKPC(String str){
		if(str.length()==0) {
			ArrayList<String>bres=new ArrayList<>();
			bres.add("");
			return bres;
		}
		
		char ch=str.charAt(0);
		String res=str.substring(1);
		ArrayList<String>ros=getKPC(res);
		ArrayList<String>mres=new ArrayList<>();
	String st=codes[ch -'0'];
	for(int i=0;i<st.length();i++) {
		char chcodes=st.charAt(i);
		for(String s:ros) {
			mres.add(chcodes + s);
		}
	}
	return mres;  
	}

	

}

