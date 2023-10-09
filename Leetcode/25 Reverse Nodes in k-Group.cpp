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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *end = head, *tmp = nullptr, *tmp2, *tail,*t;
        int i = 0;
        while(i<k){
            if(tmp == nullptr){
                tmp = end;
                tail = end;
                end = end->next;
            }
            else{
                tmp2 = end->next;
                end->next = tmp;
                tmp = end;
                end = tmp2;
            }
            i++;
        }
        tail->next = end;
        head = tmp;
        tmp = end;
        i = 1;
        while(end!=nullptr){
            end = end->next;
            i++;
            if(i==k){
                if(end!=nullptr){
                    t = tmp;
                    tmp = tmp->next;
                    tail->next->next = end->next;
                    end = end->next;
                    while(tmp!=end && tmp!=nullptr){
                        tmp2 = tmp->next;
                        tmp->next = tail->next;
                        tail->next = tmp;
                        tmp = tmp2;
                    }
                    tail = t;
                }
                i = 1;
            }
        }
        return head;
    }
};