import java.util.*;
class Main {
    
    public static void printLexo(String out, String s, char[] s_arr, boolean[] bol) {
        int com=out.compareTo(s);
        if(com > -1){
            return;
        }
        if(out.length() == s_arr.length)
        System.out.println(out);

        for(int i=0; i<s_arr.length; ++i){
            if(bol[i] == false){
                bol[i]=true;
                printLexo(out+String.valueOf(s_arr[i]), s, s_arr, bol);
                bol[i]=false;
            }
        }
    }
    public static void main(String args[]) {

        Scanner sc=new Scanner(System.in);
		
		// input string
        String s=sc.nextLine();
        char[] s_arr=s.toCharArray();
        Arrays.sort(s_arr);

        boolean bol[]=new boolean[s_arr.length];

        printLexo("", s, s_arr, bol);
        
    }
}