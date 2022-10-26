// Java program for the above approach
import java.io.*;
import java.util.*;

class GFG {

	// Function to return the result of
	// the game
	public static String gameMax(String S)
	{
		// length of the string
		int N = S.length();

		// List to maintain the lengths of
		// consecutive '1's in the string
		List<Integer> list = new ArrayList<>();

		// Variable that keeps a track of
		// the current length of the block
		// of consecutive '1's
		int one = 0;

		for (int i = 0; i < N; i++) {

			if (S.charAt(i) == '1') {
				one++;
			}
			else {

				// Adds non-zero lengths
				if (one != 0) {
					list.add(one);
				}
				one = 0;
			}
		}

		// This takes care of the case
		// when the last character is '1'
		if (one != 0) {
			list.add(one);
		}

		// Sorts the lengths in
		// descending order
		Collections.sort(list,
						Collections.reverseOrder());

		// Scores of the 2 players
		int score_1 = 0, score_2 = 0;

		for (int i = 0; i < list.size(); i++) {

			// For player 1
			if (list.get(i) % 2 == 1) {
				score_1 += list.get(i);
			}

			// For player 2
			else {
				score_2 += list.get(i);
			}
		}

		// In case of a tie
		if (score_1 == score_2)
			return "-1";

		// Print the result
		return (score_1 > score_2) ? "Player 1"
								: "Player 2";
	}

	// Driver Code
	public static void main(String[] args)
	{
		// Given string S
		String S = "11111101";

		// Function Call
		System.out.println(gameMax(S));
	}
}
