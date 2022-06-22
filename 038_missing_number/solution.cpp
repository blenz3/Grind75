class Solution {
public:
    // Strategy
    //  - Approach 1: Sum them all up and compare with the expected sum
    //  - Approach 2: Vector of bools from 1..n where we fill them in if encountered and then scan for missing
    int missingNumber(vector<int>& nums) {
        
        int expected = (nums.size() * (nums.size() + 1)) / 2;
        int actual = sum(nums);
        return ::abs(actual - expected);
        
    }
    
    inline int sum(const vector<int>& values) {
        int result(0);
        for (auto value : values) {
            result += value;
        }
        
        return result;
    }
};
