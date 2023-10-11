/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    void bfs(Node* root, unordered_map<int,vector<Node*>>& m, int h){
        if(m.find(h) == m.end()) 
            m.insert(pair<int,vector<Node*>>(h,vector<Node*>()));
        m[h].push_back(root);
        if(root->left != nullptr)
            bfs(root->left,m,h+1);
        if(root->right != nullptr)
            bfs(root->right,m,h+1);
    }
    Node* connect(Node* root) {
        if(root == nullptr) return root;
        unordered_map<int,vector<Node*>> m;
        bfs(root, m, 0);
        for(pair<int,vector<Node*>> a:m){
            for(int i=0;i<a.second.size()-1;i++){
                a.second[i]->next = a.second[i+1];
            }
        }
        return root;
    }
};