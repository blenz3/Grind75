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
    //   - Traverse the tree in order and compare the left and right subtree depths
    //   - Bubble up the depths and continue the compare
    bool isBalanced(TreeNode* root) {
        bool balanced(true);
        traverseBalanced(root, 0, balanced);
        return balanced;
    }
    
private:
    
    int traverseBalanced(TreeNode* root, int currentDepth, bool& balanced) {
        if (root == nullptr) {
            return currentDepth;
        }
        
        
        int leftDepth = traverseBalanced(root->left, currentDepth + 1, balanced);
        int rightDepth = traverseBalanced(root->right, currentDepth + 1, balanced);
            
        if (::abs(leftDepth - rightDepth) > 1) {
            balanced = false;
        }
            
            
        return std::max(leftDepth, rightDepth);
        
        
    }
};
