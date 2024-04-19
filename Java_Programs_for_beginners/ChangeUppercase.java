package Java_Programs_for_beginners;

public class ChangeUppercase {
    public static String changeToUpperCaseFromIndex(String str, int index){
        String str1 = str.substring(0, index);
        String str2 = str.substring(index, str.length()).toUpperCase();
        return str1+str2;
    }
}
