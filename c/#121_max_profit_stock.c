int maxProfit(int* prices, int pricesSize) {
    if (pricesSize <= 1) {
        return 0; /* If there are no prices or only one price, no profit can be made*/
    }
    
    int minPrice = prices[0];
    int maxProfit = 0;
    
    for (int i = 1; i < pricesSize; ++i) {
        minPrice = prices[i] < minPrice ? prices[i] : minPrice;
        
        maxProfit = (prices[i] - minPrice) > maxProfit ? (prices[i] - minPrice) : maxProfit;
    }
    
    return maxProfit;
}

/*using two pointers*/
int maxProfit(int* prices, int pricesSize) {
    if (pricesSize <= 1) {
        return 0; 
    }
    
    int left = 0;
    int right = 1;
    int maxProfit = 0;
    
    while (right < pricesSize) {
        if (prices[right] > prices[left]) {
            int profit = prices[right] - prices[left];
            maxProfit = (profit > maxProfit) ? profit : maxProfit;
        } 
        else {
            left = right;
        }

        right++;
    }
    
    return maxProfit;
}
