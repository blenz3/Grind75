class Solution {
public:
    
    // Approach 1: Dynamic programming with a vector for each number between 1..amount. For each coin
    // we initialize each of the initial values in our counts vector and then propagate them downstream.
    // We will then 
    int coinChange(vector<int>& coins, int amount) {
        if (amount == 0) {
            return 0;
        } else if (amount < 0) {
            return -1;
        }
        
        // Sort so we end up with the largest coins first
        std::sort(coins.begin(), coins.end(), std::greater<int>());
        
        // Cache all results in the amounts vector
        vector<int64_t> amounts(amount + 1, INT_MAX);
        
        // For each coin type we'll initialize all the constant multiples of that coin
        for (auto coin : coins) {
            for (int64_t count = 1; count * coin <= amount; ++count) {
                amounts[coin * count] = std::min(amounts[coin * count], count);    
            }
        }

        // Now for each amount we will see if it is reachable from any other
        for (int change = coins.back(); change <= amount; ++change) {
            
            int64_t minChange = amounts[change];
            for (auto coin : coins) {
                if (change - coin >= 0) {
                    minChange = std::min(minChange, amounts[change - coin] + 1);
                }
            }
            amounts[change] = minChange;
        }
        
        return (amounts[amount] >= INT_MAX) ? -1 : amounts[amount];
    }
};
