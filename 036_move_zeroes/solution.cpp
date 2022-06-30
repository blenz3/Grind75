class Solution {
public:
    
    // Approach 2: Write head vs read head and back populate zeroes at the end
    void moveZeroes(vector<int>& nums) {
        size_t writeHead = 0, readHead = 0;
        while (readHead < nums.size()) {
            
            // If we read a zero just skip it and overwrite with something else
            if (nums[readHead] == 0) {
                readHead++;
                continue;
            }
            
            // This number is non-zero so we will overwrite it
            nums[writeHead++] = nums[readHead++];
        }
        
        // Overwrite the last values with zeroes
        while (writeHead < nums.size()) {
            nums[writeHead++] = 0;
        }
    }
    
#if 0
    // Approach 1: create a copy and only copy over non zero values
    void moveZeroes(vector<int>& nums) {
        
        vector<int> out(nums.size(), 0);
        size_t writeHead = 0;
        for (auto num : nums) {
            if (num != 0) {
                out[writeHead++] = num;
            }
        }
        nums = out;
    }
#endif
};
