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
    void inorder(TreeNode* root, vector<int>& v){
        if(root == nullptr) return;
        if(root->left != nullptr) inorder(root->left, v);
        v.push_back(root->val);
        if(root->right != nullptr) inorder(root->right, v);
    }
    int getMinimumDifference(TreeNode* root) {
        vector<int> v;
        inorder(root, v);
        int minV = v[1] - v[0];
        for(int i = 2; i<v.size();i++){
            minV = min(v[i] - v[i-1], minV);
        }
        return minV;
    }
};