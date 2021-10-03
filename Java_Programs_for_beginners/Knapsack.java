package DP;

public class knapsack {
    public static int knap(int wt[], int price[], int cap, int vi) {

        if (vi == wt.length)
            return 0;
        int excluded = knap(wt, price, cap, vi + 1);
        int include = 0;
        if (cap >= wt[vi])
            include = knap(wt, price, cap - wt[vi], vi + 1) + price[vi];
        return Math.max(excluded, include);

    }

    public static int knapTD(int wt[], int price[], int cap, int vi, int strg[][]) {
        if (strg[vi][cap] != 0)
            return strg[vi][cap];
        if (vi == wt.length)
            return 0;
        int excluded = knap(wt, price, cap, vi + 1);
        int include = 0;
        int ans = 0;
        if (cap >= wt[vi])
            include = knapTD(wt, price, cap - wt[vi], vi + 1, strg) + price[vi];

        ans = Math.max(excluded, include);
        strg[vi][cap] = ans;
        return ans;

    }

    public static void main(String[] args) {
        // TODO Auto-generated method stub
        int wt[] = {1, 3, 4, 5};
        int p[] = {1, 4, 5, 7};
        System.out.println(knap(wt, p, 9, 0));
        System.out.println(knapTD(wt, p, 9, 0, new int[wt.length + 1][10]));

    }

}
