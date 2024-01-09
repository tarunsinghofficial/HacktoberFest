package Java_Programs_for_beginners;

public class LongestIncreasingSubsequence {

    public static int longestIncreasingSubsequence(int[] arr) {
        int n = arr.length;
        int[] lis = new int[n];
        for (int i = 0; i < n; i++) {
            lis[i] = 1;
        }

        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (arr[i] > arr[j] && lis[i] < lis[j] + 1) {
                    lis[i] = lis[j] + 1;
                }
            }
        }

        int maxLength = 0;
        for (int length : lis) {
            if (length > maxLength) {
                maxLength = length;
            }
        }

        return maxLength;
    }

    public static void main(String[] args) {
        int[] arr = {10, 22, 9, 33, 21, 50, 41, 60, 80};
        int result = longestIncreasingSubsequence(arr);
        System.out.println("En uzun artan alt dizi uzunluğu: " + result);
    }

}
