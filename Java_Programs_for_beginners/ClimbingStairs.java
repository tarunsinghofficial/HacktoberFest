class solution {
    public int stairPath(int SRC, int dst, int dp[]) {
        // flow goes right to left
        for (int src = dst; src >= 0; src--) {
            if (src == dst) {
                dp[src] = 1;
                continue;
            }
            // 2 jump only
            int count = 0;
            for (int jump = 1; jump <= 2; jump++) {
                if (src + jump <= dst) {
                    count += dp[src + jump];
                }

            }
            dp[src] = count;
        }
        return dp[SRC]; // return steps from 0th idx
    }

    public int climbStairs(int n) {
        int dp[] = new int[n + 1];
        return stairPath(0, n, dp);
    }
}




