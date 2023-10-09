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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == nullptr) return head;
        ListNode *tmp = head;
        int cnt = 1;
        while(tmp->next != nullptr){
            tmp = tmp->next;
            cnt++;
        }
        tmp->next = head;
        k %= cnt;
        int i=0;
        while(i<cnt-k){
            if(i+1 == cnt-k){
                tmp = head;
            }
            head = head->next;
            i++;
        }
        tmp->next = nullptr;
        return head;
    }
};