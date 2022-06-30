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
    // Approach 1: Traverse tree and upon discovering a matching root then compare
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        bool matched(false);
        traverse(root, subRoot, matched);
        return matched;
    }
    
private:
    
    void traverse(TreeNode* root, TreeNode* subRoot, bool& fullyMatched) {
        if (root == nullptr) {
            return;
        }
        
        if (root->val == subRoot->val && !fullyMatched) {
            fullyMatched = compareTrees(root, subRoot);
        }
        
        traverse(root->left, subRoot, fullyMatched);
        traverse(root->right, subRoot, fullyMatched);
    }
    
    bool compareTrees(TreeNode* root, TreeNode* subRoot) {
        if ((root != nullptr) != (subRoot != nullptr)) {
            return false;
        } else if (subRoot == nullptr) {
            return true;
        }
        
        if (root->val != subRoot->val) {
            return false;
        }
        
        auto leftTree = compareTrees(root->left, subRoot->left);
        auto rightTree = compareTrees(root->right, subRoot->right);
        return (leftTree && rightTree);
    }
};
