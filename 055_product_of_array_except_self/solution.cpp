class Solution {
public:

    //  - Approach 2: Capture a total product and then apply it backwards
    vector<int> productExceptSelf(vector<int>& nums) {
        
        // Capture total product excluding zeroes
        int zeroes(0), negatives(0), product(1);
        for (auto num : nums) {
            if (num == 0) 
                zeroes++;
            else if (num < 0)
                negatives++;
            
            if (num < 0 || num > 0) {
                product *= abs(num);
            }
        }
        
        // Back populate the exclusionary products
        for (auto& num : nums) {
            // Handle zeroes
            if (num == 0 && zeroes - 1 != 0) {
                num = 0;
            } else if (num == 0) {
                num = sign(negatives) * product;
            } else if (zeroes != 0) {
                num = 0;
            } else if (num < 0) {
                num = (sign(negatives - 1) * product) / ::abs(num);
            } else {
                num = (sign(negatives) * product) / num;
            }
        }
        
        return nums;
    }
    
    int sign(int negativeCount) {
        return (negativeCount % 2 == 0) ? 1 : -1;
    }
    
#if 0
    //  - Approach 1: For each index we multiply all other elements 
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> out(nums.size(), 1);
        for (int i = 0; i < nums.size(); ++i) {
            for (int j = 0; j < nums.size(); ++j) {
                if (i == j) {
                    continue;
                }
                
                out[i] *= nums[j];
            }
        }
        return out;   
    }
#endif
};
