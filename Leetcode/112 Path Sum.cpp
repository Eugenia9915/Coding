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
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root == nullptr) return false;
        if((targetSum - root->val) == 0 && root->left == nullptr && root->right == nullptr)
            return true;
    
        bool tmp = false;
        if(root->left != nullptr)
            tmp = tmp || hasPathSum(root->left, targetSum - root->val);
        if(root->right != nullptr && !tmp)
            tmp = tmp || hasPathSum(root->right, targetSum - root->val);
        return tmp;
    }
};