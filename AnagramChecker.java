import java.util.*;
public class AnagramChecker{
    public static void main(String[] args){
        Scanner sc=new Scanner(System.in);
        String s1=sc.next();
        String s2=sc.next();

        boolean flag=anagramCheck(s1,s2);
        if(!flag){
            //statement to be executed if not anagram
            System.out.println("not");
        }else{
            //statement to be executed if anagram
            System.out.println("are");
        }
    }
    static boolean anagramCheck(String s1,String s2){
        int n1=s1.length(),n2=s2.length();
        if(n1!=n2) return false;
        StringBuilder temp=new StringBuilder(s2);
        boolean flag=true;
        for(int i=0;i<n1;i++){
            flag=false;
            for(int j=0;j<n2;j++){
                if(s1.charAt(i)==temp.charAt(j)){
                    temp.deleteCharAt(j);
                    n2--;
                    flag=true;
                    break;
                }
            }
            if(!flag) break;
        }
        return flag;
    }
}
