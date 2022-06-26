/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    // Strategy
    //  - Approach 1: Compare each node with its path from the root
    //  - Approach 2: Propagate min/max values through an inorder traversal
    bool isValidBST(TreeNode* root) {
       return traverse(root->left, std::numeric_limits<int64_t>::min(), root->val) && traverse(root->right, root->val, std::numeric_limits<int64_t>::max()); 
    }
    
private:
    bool traverse(TreeNode* root, int64_t minValue, int64_t maxValue) {
        if (root == nullptr) {
            return true;
        }
        
        if (root->val <= minValue || root->val >= maxValue) {
            // std::cout << "val " << root->val << " min " << minValue << " max " << maxValue << std::endl;
            
            return false;
        }
        
        return (traverse(root->left, minValue, root->val) && traverse(root->right, root->val, maxValue));
    }
};
