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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        TreeNode *ans = new TreeNode(postorder[postorder.size()-1]);
        if(inorder.size() == 1) return ans;

        int root;
        for(int i=0;i<inorder.size();i++){
            if(inorder[i] == postorder[postorder.size()-1]){
                root = i;
                break;
            }
        }
        vector<int> left_in(inorder.begin(), inorder.begin()+root);
        vector<int> right_in(inorder.begin()+root+1,inorder.end());
        vector<int> left_post(postorder.begin(), postorder.begin()+left_in.size());
        vector<int> right_post(postorder.begin()+left_in.size(), postorder.begin()+postorder.size()-1);
        ans->left = left_in.size() == 0 ? nullptr : buildTree(left_in, left_post);
        ans->right = right_in.size() == 0 ? nullptr : buildTree(right_in, right_post);
        return ans;
    }
};