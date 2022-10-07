
public class BuySellStock{

	public int maxProfit(int[] prices) {
        int n = prices.length;
        if(n == 1){
            return 0;
        }
        int max  = 0, min = prices[0];
        for(int i = 1; i < n; i++){
            max = Math.max(max, prices[i] - min);
            min = Math.min(min, prices[i]);
        }
        return max;
    }
}