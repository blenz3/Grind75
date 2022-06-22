class Solution {
public:
    // Strategy
    //  - Approach 1: Hashtable count each element
    //  - Approach 2: Sort and count elements
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> counts;
        int maxElement(nums[0]), maxCount(1);
        for (auto num : nums) {
            if (++counts[num] > maxCount) {
                maxCount = counts[num];
                maxElement = num;
            }
        }
        
        return maxElement;
    }
};
