class Solution {
public:
    // Approach 1: Create subsets where we recursively add the values or not
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> currentSet;
        vector<vector<int>> allPermutations;
        unordered_set<int> used;
        generatePermutations(nums, 0, currentSet, allPermutations, used);
        return allPermutations;
    }
    
private:
    void generatePermutations(const vector<int>& nums, size_t index, vector<int>& path, vector<vector<int>>& out, unordered_set<int>& used) {
        if (index == nums.size()) {
            out.push_back(path);
            return;
        }
        
        for (int i = 0; i < nums.size(); ++i) {
            // Already added earlier
            if (used.count(nums[i]) != 0) {
                continue;
            }
            
            used.insert(nums[i]);
            
            path.push_back(nums[i]);
            generatePermutations(nums, index + 1, path, out, used);
            path.pop_back();
            
            used.erase(nums[i]);
        }
    }
};
