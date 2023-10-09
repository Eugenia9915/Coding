/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        unordered_map<ListNode*,int> m;
        ListNode *tmp = head;
        while(tmp!=nullptr){
            if(m.find(tmp) == m.end())
                m.insert(pair<ListNode*,int>(tmp,1));
            else
                return true;
            tmp = tmp->next;
        }
        return false;
    }
};