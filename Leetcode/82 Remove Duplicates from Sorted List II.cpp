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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *tmp = head, *r, *prev;
        while(tmp!=nullptr){
            if(tmp->next != nullptr && tmp->val == tmp->next->val){
                r = tmp->next;
                while(r != nullptr && tmp->val == r->val) r = r->next;
                if(tmp == head) head = r;
                else{
                    prev->next = r;
                    tmp = r;
                }
            }else{
                prev = tmp;
                tmp = tmp->next;
            }
        }
        return head;
    }
};