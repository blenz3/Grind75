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
    int maxDepth(TreeNode* root) {
        return traverse(root, 0);
    }
    
private:
    int traverse(TreeNode* root, int depth) {
        if (root == nullptr) {
            return depth;
        }
        
        auto leftDepth = traverse(root->left, depth + 1);
        auto rightDepth = traverse(root->right, depth + 1);
        return std::max(leftDepth, rightDepth);
    }
};
