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
    ListNode* reverseList(ListNode* head) {
        ListNode *tmp = head, *rev = nullptr;
        if(head == nullptr || head->next == nullptr) return head;
        while(tmp != nullptr){
            if(rev == nullptr){
                rev = new ListNode(tmp->val);
            }
            else{
                ListNode *a = new ListNode(tmp->val, rev);
                rev = a;
            }
            tmp = tmp->next;
        }
        return rev;
    }
};