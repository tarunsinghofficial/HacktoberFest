def maxProfit(prices):
    if not prices:
        return 0
    
    # Initialize states
    buy1 = buy2 = float('-inf')
    sell1 = sell2 = 0
    
    for price in prices:
        # First buy: maximize money left after buying the first stock
        buy1 = max(buy1, -price)
        # First sell: maximize profit after first sell
        sell1 = max(sell1, buy1 + price)
        # Second buy: maximize profit left after second buy
        buy2 = max(buy2, sell1 - price)
        # Second sell: maximize profit after second sell
        sell2 = max(sell2, buy2 + price)
    
    return sell2


# Example usage:
if __name__ == "__main__":
    prices = [3,3,5,0,0,3,1,4]
    print("Maximum Profit with at most 2 transactions:", maxProfit(prices))
