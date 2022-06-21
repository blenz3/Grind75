class Solution {
public:
    // Strategy
    //   - Facts
    //      - Numbers are postive or negative
    //      - If they were only positive I guess it'd just be all numbers
    //  - Algo
    //      - Option 1: Brute Force
    //          - For each i,j evaluate the sum. If it's better than the best so far capture it
    //          - Runtime quadratic
    //          - Space constant
    //      - Option 2: Greedy
    //          - Accumulate all numbers 
    //          - If at any point the sum goes negative stop tracking that accumulation
    //          - For each number added to our tracking sum we compare with the max sum so far
    //          - Runtime linear
    //          - Space constant
    int maxSubArray(vector<int>& nums) {
        if (nums.empty()) 
            return 0;
        
        int maxProfit(INT_MIN), sum(0);
        for (int i = 0; i < nums.size(); ++i) {
            sum += nums[i];
            maxProfit = std::max(maxProfit, sum);
            if (sum < 0) {
                sum = 0;
            }
        }
        return maxProfit;
    }
};
