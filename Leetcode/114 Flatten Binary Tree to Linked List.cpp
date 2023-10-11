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
    void flatten(TreeNode* root) {
        if(root == nullptr) return;
        TreeNode *r = root, *tmp, *t;
        while(r->right != nullptr || r->left != nullptr){
            if(r->left != nullptr){
                tmp = r->right;
                r->right = r->left;
                t = r->right;
                while(t->right != nullptr) t = t->right;
                t->right = tmp;
                r->left = nullptr;
            }
            r = r->right;
        }
    }
};