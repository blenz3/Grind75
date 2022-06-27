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
    // Approach 1: Traverse in order and add the values to a multidimensional vector as we go
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> levels;
        traverse(root, 0, levels);
        return levels;
    }
    
private:
    void traverse(TreeNode* root, size_t level, vector<vector<int>>& levels) {
        if (root == nullptr)
            return;
        
        if (levels.size() == level) {
            levels.push_back({ root->val });
        } else {
            levels[level].push_back(root->val);
        }
        
        traverse(root->left, level + 1, levels);
        traverse(root->right, level + 1, levels);
    }
};
