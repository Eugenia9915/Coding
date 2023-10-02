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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *head,*tail;
        head=tail=nullptr;
        if(!l1 && !l2)return nullptr;
        else if(l1 && !l2)return l1;
        else if(!l1 && l2)return l2;
        else{
            while(l1 || l2){
                if(l1->val <= l2->val){
                    if(head==nullptr)
                        head=tail=new ListNode(l1->val);
                    else{
                        tail->next=new ListNode(l1->val);
                        tail=tail->next;
                    }
                    l1=l1->next;
                }
                else{
                    if(head==nullptr)
                        head=tail=new ListNode(l2->val);
                    else{
                        tail->next=new ListNode(l2->val);
                        tail=tail->next;
                    }
                    l2=l2->next;
                }
                if(!l1){
                    tail->next=l2;
                    break;
                }
                else if(!l2){
                    tail->next=l1;
                    break;
                }
            }
        }
        return head;
    }
};