
public class FirstLetterAppearTwice{

	public char repeatedCharacter(String s) {
        int arr[] = new int[26];
        for(int i = 0; i < s.length(); i++){
            int p = ((int)s.charAt(i)) - 97;
            arr[p]++;
            if(arr[p] == 2){
                return s.charAt(i);
            }
        }
        return 'a';
    }
}