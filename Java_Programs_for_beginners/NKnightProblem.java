
import java.util.Scanner;

public class NKnightProblem {

	private static Scanner sc;

	public static void main(String[] args) {
		sc = new Scanner(System.in);
		int n = sc.nextInt();

		boolean board[][] = new boolean[3][4];

		int c = allc(0, 0, 0, board);
		System.out.println(c);
		 all(0,0,0, "", board);

	}

	public static int allc(int row, int col, int kpsf,boolean v[][]) {
		if (kpsf == v.length) {                    //knight placed so far
			//System.out.print(ans + " ");
			return 1;
		}

		int count = 0;

		for (int c = col; c < v[0].length; c++) {
			if (issafe(row, c, v)) {

				v[row][c] = true;

				count = count + allc(row, c + 1, kpsf + 1, v);
				v[row][c] = false;
			}

		}

		for (int r = row + 1; r < v.length; r++) {
			for (int c = 0; c < v[0].length; c++) {
				if (issafe(r, c, v)) {

					v[r][c] = true;
					count = count + allc(r, c + 1, kpsf + 1,v);
					v[r][c] = false;
				}

			}
		}
		return count;

	}

	public static void all(int row, int col, int kpsf,String ans, boolean v[][]) {
		if (kpsf == v.length) {
			
			System.out.println(ans + " ");
			return ;
		}

		

		for (int c = col; c < v[0].length; c++) {
			if (issafe(row, c, v)) {

				v[row][c] = true;

				 all(row, c + 1, kpsf + 1, ans + "{" + row + "-" + c + "}" + " ", v);
				v[row][c] = false;
			}

		}

		for (int r = row + 1; r < v.length; r++) {
			for (int c = 0; c < v[0].length; c++) {
				if (issafe(r, c, v)) {

					v[r][c] = true;
					all(r, c + 1, kpsf + 1, ans + "{" + r + "-" + c + "}" + " ",v);
					v[r][c] = false;
				}

			}
		}
		

	}


	public static boolean issafe(int row, int col, boolean v[][]) {

		if (v[row][col])
			return false;

		int c = col;
		int r = row - 2;
		if (r >= 0 && c + 1 < v.length) {
			if (v[r][c + 1])
				return false;
		}
		if (r >= 0 && c - 1 >= 0) {
			if (v[r][c - 1])
				return false;
		}
		r = row - 1;
		c = col;
		if (r >= 0 && c - 2 >= 0) {
			if (v[r][c - 2])
				return false;
		}
		if (r >= 0 && c + 2 < v.length) {
			if (v[r][c + 2])
				return false;
		}

		

		return true;
	}

}
