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
        ListNode* n_head = new ListNode(0);
        ListNode* t = n_head;

        int s=0;
        while(l1 || l2){
            if(l1){
                s = s+l1->val;
                l1 = l1->next;
            }
            if(l2){
                s = s +l2->val;
                l2= l2->next;
            }

            t->next = new ListNode(s%10);
            t = t->next;
            s = s/10;
        }

        if(s!=0) t->next = new ListNode(s%10);
        return n_head->next;
    }
};