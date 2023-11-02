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
    bool isValidBST(TreeNode* root) {
        if(!root) return true;
        TreeNode *tmp;
        if(root->left){
            tmp = root->left;
            while(tmp->right) tmp = tmp->right;
            if(tmp->val >= root->val) return false;
        }
        if(root->right){
            tmp = root->right;
            while(tmp->left) tmp = tmp->left;
            if(tmp->val <= root->val) return false;
        }
        return isValidBST(root->left) && isValidBST(root->right);
    }
};