package Ds.Queue;
import java.util.*;

public class slidingWindow {
    public static void main(String[] args) {
        Solution sol = new Solution();
        int[] a = {4, 3, 1, 2, 5, 3, 4, 7, 1, 9};
        int[] ans = sol.maxSlidingWindow(a, 4);
        for (int x : ans) {
            System.out.print(x + " ");
        }
    }

    static class Solution {
        public int[] maxSlidingWindow(int[] a, int k) {
            int n = a.length;
            if (n == 0) return a;

            Deque<Integer> dq = new LinkedList<>();
            int[] ans = new int[n - k + 1];
            int i = 0;

            // Process the first window (first k elements)
            for (; i < k; i++) {
                // Remove elements from the deque that are smaller than the current element
                while (!dq.isEmpty() && a[dq.peekLast()] <= a[i]) {
                    dq.removeLast();
                }
                dq.addLast(i); // Add current element index
            }

            // Process the rest of the array
            for (; i < n; i++) {
                // The front of the deque is the largest element for the previous window
                ans[i - k] = a[dq.peekFirst()];

                // Remove indices that are out of this window (i-k is the index outside of the current window)
                if (!dq.isEmpty() && dq.peekFirst() <= i - k) {
                    dq.removeFirst();
                }

                // Remove all elements smaller than the current element from the back of the deque
                while (!dq.isEmpty() && a[dq.peekLast()] <= a[i]) {
                    dq.removeLast();
                }
                dq.addLast(i); // Add current element index
            }

            // Add the maximum for the last window
            ans[i - k] = a[dq.peekFirst()];

            return ans;
        }
    }
}
