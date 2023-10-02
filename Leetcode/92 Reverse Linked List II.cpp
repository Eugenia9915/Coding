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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode *tmp = head, *lptr = nullptr, *rptr = nullptr;
        ListNode *rev = nullptr, *tail, *last;
        int cnt = 1;
        if(head->next == nullptr || right-left == 0) return head;
        while(tmp != nullptr){
            if(cnt >= left && cnt <= right){
                if(rev == nullptr){
                    rev = new ListNode(tmp->val);
                    last = rev;
                }
                else{
                    ListNode *a = new ListNode(tmp->val, rev);
                    rev = a;
                }
            }
            tmp = tmp->next;
            cnt++;
        }

        // cout<<cnt<<endl;
        int total = cnt-1;
        if(left == 1 && right == total) return rev;
        
        tmp = head;
        cnt = 1;
        while(tmp->next != nullptr){
            if(left!=1 && cnt+1 == left) lptr = tmp;
            else if(right != total && cnt == right) rptr = tmp->next;
            tmp = tmp->next;
            cnt++;
        }
        
        if(left == 1 && right != total){
            last->next = rptr;
            head = rev;
        }
        else if(left != 1 && right == total){
            lptr->next = rev;
        }
        else{
            lptr->next = rev;
            last->next = rptr;
        }

        return head;
    }
};