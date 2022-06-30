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
    
    // Approach 2: Collect all nodes with a value matching the root and then compare them all
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        vector<TreeNode*> starts;
        traverse(root, subRoot, starts);
        
        bool matched(false);
        for (auto start : starts) {
            if (matched = compareTrees(start, subRoot))
                break;
        }
        
        return matched;
    }
    
    void traverse(TreeNode* root, TreeNode* subRoot, vector<TreeNode*>& starts) {
        if (root == nullptr) {
            return;
        }
        
        if (root->val == subRoot->val) {
            starts.push_back(root);
        }
        
        traverse(root->left, subRoot, starts);
        traverse(root->right, subRoot, starts);
    }
    
#if 0
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

#endif
    
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
