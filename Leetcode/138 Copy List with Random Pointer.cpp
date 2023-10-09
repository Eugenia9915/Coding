/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*,Node*> m;
        Node *tmp = head, *ans=nullptr, *t, *head_tmp;
        while(tmp!=nullptr){
            t = new Node(tmp->val);
            m.insert(pair<Node*,Node*>(tmp,t));
            if(ans==nullptr){
                ans = t;
                head_tmp = ans;
            }
            else{
                head_tmp->next = t;
                head_tmp = head_tmp->next;
            }
            tmp = tmp->next;
        }
        tmp = head;
        head_tmp = ans;
        while(tmp!=nullptr){
            if(tmp->random!=nullptr)
                head_tmp->random = m[tmp->random];
            head_tmp = head_tmp->next;
            tmp = tmp->next;
        }
        return ans;
    }
};