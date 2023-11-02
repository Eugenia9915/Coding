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
    void dfs(TreeNode* root, int targetSum, vector<int> t,vector<vector<int>>& v){
        t.push_back(root->val);
        if(!root->left && !root->right && targetSum != root->val){}
        else if(!root->left && !root->right && targetSum == root->val)
            v.push_back(t);
        else{
            if(root->left)
                dfs(root->left, targetSum-root->val,t,v);
            if(root->right)
                dfs(root->right, targetSum-root->val,t,v);
        }
        t.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        if(!root) return ans;
        vector<int> t;
        dfs(root,targetSum,t,ans);
        return ans;
    }
};