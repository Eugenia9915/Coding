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
class BSTIterator {
public:
    vector<int> v;
    int index;
    void add_nums(TreeNode *root){
        if(root->left == nullptr && root->right == nullptr)
            v.push_back(root->val);
        else{
            if(root->left !=nullptr)
                add_nums(root->left);
            v.push_back(root->val);
            if(root->right !=nullptr)
                add_nums(root->right);
        }
    }
    BSTIterator(TreeNode* root) {
        add_nums(root);
        index = 0;
    }
    
    int next() {
        int ans;
        if(index < v.size()){
            ans = v[index];
            index++;
            return ans;
        }
        else return -1;
    }
    
    bool hasNext() {
     return index < v.size() ? true : false;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */