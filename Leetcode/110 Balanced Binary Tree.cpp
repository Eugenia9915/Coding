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
    int max_height(TreeNode *root){
        if(!root) return 0;
        return 1 + max(max_height(root->left), max_height(root->right));
    }
    bool isBalanced(TreeNode* root) {
        if(!root) return true;
        if(abs(max_height(root->left)-max_height(root->right)) > 1)
        return false;
        return isBalanced(root->left) && isBalanced(root->right);
    }
};