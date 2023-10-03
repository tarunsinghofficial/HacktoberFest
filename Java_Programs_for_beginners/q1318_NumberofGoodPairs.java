import java.util.HashMap;

class Solution {
    public int numIdenticalPairs(int[] nums) {
        HashMap<Integer, Integer> counts = new HashMap<>();
        int ans = 0;

        for (int num: nums) {
            ans += counts.getOrDefault(num, 0);
            counts.put(num, counts.getOrDefault(num, 0) + 1);
        }
        
        return ans;
    }
}

/*
Runtime
Details
1ms
Beats 86.48%of users with Java

Memory
Details
39.99MB
Beats 34.90%of users with Java
 * 
 */