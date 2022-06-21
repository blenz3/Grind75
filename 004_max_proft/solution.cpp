class Solution {
public:
    // Strategy
    //  - Facts
    //      - Prices always postive (or zero)
    //      - Can only buy and sell once
    //  - Strategy
    //      - One pass across input space while accumulating the lowest price so far and a max profit so far
    //      - For each future value we compare the max profit of buying at lowest and selling at that value
    //        with our max profit so far
    //      - Runtime linear
    //      - Space constant
    int maxProfit(vector<int>& prices) {
        int maxProfitPossible = 0, minPrice = INT_MAX;
        for (int i = 0; i < prices.size(); ++i) {
            maxProfitPossible = std::max(prices[i] - minPrice, maxProfitPossible);
            minPrice = std::min(minPrice, prices[i]);
        }
        
        return maxProfitPossible;
    }
};
