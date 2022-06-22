class Solution {
public:
    
    // Dyanmic Programming with space
    //  - Recursively call a 1 step or a 2 step with memoization
    int climbStairs(int n) {
        if (n == 1) {
            return 1;
        } else if (n == 2) {
            return 2;
        } 
        auto findIt = memo.find(n);
        if (findIt == memo.end()) {
            int result = climbStairs(n - 1) + climbStairs(n - 2);
            memo[n] = result;
            return result;
        }
        
        return findIt->second;
    }
    
private:
    unordered_map<int, int> memo;
};
