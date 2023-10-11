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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        TreeNode *ans = new TreeNode(preorder[0]);
        if(preorder.size() == 1) return ans;

        int root;
        for(int i=0;i<inorder.size();i++)
            if(inorder[i] == preorder[0]){
                root = i;
                break;
            }
        vector<int> left_pre(preorder.begin()+1,preorder.begin()+root+1);
        vector<int> right_pre(preorder.begin()+root+1,preorder.end());
        vector<int> left_in(inorder.begin(), inorder.begin()+root);
        vector<int> right_in(inorder.begin()+root+1,inorder.end());
        ans->left = left_pre.size() == 0 ? nullptr : buildTree(left_pre, left_in);
        ans->right = right_pre.size() == 0 ? nullptr : buildTree(right_pre, right_in);
        return ans;
    }
};