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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root == nullptr) return ans;
        queue<TreeNode*> q;
        vector<int> tmp;
        q.push(root);
        int n;
        bool l = true;
        while(!q.empty()){
            n = q.size();
            for(int i=0;i<n;i++){
                if(l) tmp.push_back(q.front()->val);
                else tmp.insert(tmp.begin(), q.front()->val);
                if(q.front()->left != nullptr) q.push(q.front()->left);
                if(q.front()->right != nullptr) q.push(q.front()->right);
                q.pop();
            }
            ans.push_back(tmp);
            tmp.clear();
            l = !l;
        }
        return ans;
    }
};