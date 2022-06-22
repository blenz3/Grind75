class Solution {
public:
    // Strategy
    //  - Approach 1: Hashtable w/ counts return true if any have a count > 1
    //  - Approach 2: Sort elements and traverse to see if any element appears twice
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> encounteredNumbers;
        for (auto num : nums) {
            if (encounteredNumbers.count(num) != 0)
                return true;
            
            encounteredNumbers.insert(num);
        }
        
        return false;
    }
};
