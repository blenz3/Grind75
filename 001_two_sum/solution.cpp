class Solution {
public:
    // Strategy
    //  - Facts
    //      - Input not sorted
    //      - Input is postive or negative
    //  - Algo
    //      - Approach 1
    //          - Sort and then two pointers until we find the target (or not)
    //          - Runtime nlgn + n == O(nlgn)
    //          - Space constant
    //      - Approach 2
    //          - Use hashtable to lookup the complement of the target and each value
    //          - Runtime 2n == O(n)
    //          - Space linear
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, vector<int>> values;
        for (int i = 0; i < nums.size(); ++i) {
            values[nums[i]].push_back(i);
        }
        
        for (int i = 0; i < nums.size(); ++i) {
            int complement = target - nums[i];
            auto findIt = values.find(complement);
            if (findIt == values.end())
                continue;
            
            auto& matchingIndices = findIt->second;
            if (matchingIndices.size() == 1 && matchingIndices.front() == i) {
                continue;
            }
            
            
            int matchingIndex = (matchingIndices.front() == i) ? matchingIndices.back() : matchingIndices.front(); 
            return std::vector<int>{i, matchingIndex};
        }
        
        return std::vector<int>{};
    }
};
