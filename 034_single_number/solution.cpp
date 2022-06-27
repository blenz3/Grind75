class Solution {
public:
    // Strategy
    //  - Approach 1: Put each number in an unordered map. When the count == 2 for a number then delete
    //  - Approach 2: Bitwise magic wherein we xor everything together and at the end we should have the number
    //  - Approach 3: Sort and compare 
    
    int singleNumber(vector<int>& nums) {
        int64_t accumulation(0);
        for (auto num : nums) {
            accumulation ^= num;
        }
        
        return accumulation;
    }
    
#if 0 // Bad approach: 2
    int singleNumber(vector<int>& nums) {
        unordered_map<int, int> counts;
        for (auto num : nums) {
            if (++counts[num] == 2) {
                counts.erase(num);
            } 
        }
        return counts.begin()->first;
    }
#endif
};
