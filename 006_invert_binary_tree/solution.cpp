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
    //  - Facts
    //      - Inverted binary tree is one where all left and right subtrees are swapped
    //  - Algo
    //      - Traverse the tree in order and just swap left and right subtrees
    //      - Runtime is linear with respect to the number of nodes
    //      - Space is linear (stack)
#if 0
    TreeNode* invertTree(TreeNode* root) {
        if (root == nullptr) {
            return root;
        }
        
        std::swap(root->left, root->right);
        invertTree(root->left);
        invertTree(root->right);
        return root;
    }
#endif
    
    TreeNode* invertTree(TreeNode* root) {
        if (root == nullptr) 
            return nullptr;
        
        
        stack<TreeNode*> nodes;
        nodes.push(root);
        while (!nodes.empty()) {
            auto top = nodes.top();
            if (top == nullptr) {
                nodes.pop();
                continue;
            }
            
            nodes.pop();
            std::swap(top->left, top->right);
            nodes.push(top->right);
            nodes.push(top->left);
            
            
        }
        
        return root;
    }
};
