int maxProfit(int* prices, int pricesSize){
    int max = 0;
    for (int i = 1; i < pricesSize; i++) {
        if (prices[i] > prices[i-1]){ //if stock price greater than yesterday
            max += prices[i] - prices[i-1]; //sell the stock and add to max profit
        }
    }
    return max;
}

//Greedy algorithm, O(n) time, O(1) space
