class Solution(object):
    def maxProfit(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """
        #idea
        # f[i] = i-nd 's max profit
        # f[i] = max(f[i-1], prices[i] - min(prices[0:i]))
        # f[0] = 0
        
        if len(prices) == 0:
            return 0
        f = len(prices)*[0]
        
        min_price = prices[0]
        for i in range(1,len(prices)):
            if prices[i] < min_price: 
                min_price = prices[i]
            f[i] = max(f[i-1], prices[i] - min_price)


        return f[len(prices)-1]
