/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    int o = 0;
    ListNode* ans = new ListNode(o);
    ListNode* p = ans;
     while(l1 != nullptr || l2 != nullptr){
        int v1 = l1 == nullptr ? 0 : l1->val;
        int v2 = l2 == nullptr ? 0 : l2->val;
        int v = (v1 + v2 + o) % 10;
        o = (v1 + v2 + o) / 10;
        // cout<<"v1="<<v1<<" v2="<<v2<<endl;
        // cout<<v<<" "<<o<<endl;
        p->val = v;
        if(l1 != nullptr) l1 = l1->next;
        if(l2 != nullptr) l2 = l2->next;
        //  cout<<p->val<<endl;
        if(l1 != nullptr || l2 != nullptr){
            p->next = new ListNode(o);
            p = p->next;
        }
        else if(o!=0){
            p->next = new ListNode(o);
        }
        else{}
     }
    //  p = ans;
    //  while(p != nullptr){
    //      cout<<p->val<<endl;
    //      p=p->next;
    //  }
        return ans; 
    }
};