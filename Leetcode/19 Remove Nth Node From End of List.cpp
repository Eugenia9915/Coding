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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head->next == nullptr) return nullptr;
        int i = 1;
        ListNode *end = head, *index = head, *prev = nullptr;
        while(i<n){
            end = end->next;
            i++;
        }
        while(end->next != nullptr){
            index = index->next;
            end = end->next;
            if(prev == nullptr) prev = head;
            else prev = prev->next;
        }
        if(prev == nullptr) head = index->next;
        else prev->next = index->next;
        return head;
    }
};