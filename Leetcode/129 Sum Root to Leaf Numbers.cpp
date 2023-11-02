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
    void add_nums(TreeNode* root, int num, vector<int>& v){
        if(root->left == nullptr && root->right == nullptr){
            v.push_back(num*10 + root->val);
        }
        else{
            if(root->left != nullptr)
                add_nums(root->left, num*10 + root->val, v);
            if(root->right != nullptr)
                add_nums(root->right, num*10 + root->val, v);
        }
    }
    int sumNumbers(TreeNode* root, int num = 0) {
        vector<int> v;
        int ans = 0;
        add_nums(root,0,v);
        for(int i=0;i<v.size();i++) ans += v[i];
        return ans;
    }
};