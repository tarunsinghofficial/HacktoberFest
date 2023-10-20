import java.util.Arrays;

public class Main {

	public static void main(String[] args) {
		char vowels[] = {'a', 'e', 'i', 'o', 'u'};
		
		char key = 'i';
		
		int foundItemIndex = Arrays.binarySearch(vowels, key);
		
		System.out.println("The given vowel is at index: " + foundItemIndex);

	}
}
