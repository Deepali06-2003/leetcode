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
        ListNode* temp = head;
        if(head == NULL || k==0) return head;
        int n=0;

        while(temp != NULL){
            n++;
            temp = temp->next;
        }

        k = k%n;
        if(k==0 || k==n) return head;

        ListNode* s = head;
        ListNode* f = head;

        while(k != 0){
            f = f->next;
            k--;
        }
        while(f->next != NULL){
            s = s->next;
            f= f->next;
        }

        f->next  = head;
        head = s->next;
        s->next = NULL;
        return head;
    }
};