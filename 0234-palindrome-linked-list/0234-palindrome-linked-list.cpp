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
ListNode* reverse(ListNode* head){
    ListNode* curr = head;
    ListNode* prev = NULL;
    ListNode* n_curr ;

    while(curr){
        n_curr = curr->next;
        curr->next = prev;

        prev = curr;
        curr = n_curr;
    }
    return prev;
}

    bool isPalindrome(ListNode* head) {
        if(head == NULL || head->next == NULL) return true;

        ListNode* s = head;
        ListNode* f = head;

        while(f->next != NULL && f->next->next != NULL){
            s=s->next;
            f= f->next->next;
        }
        ListNode* newL = s->next;
        s->next = NULL;
        newL = reverse(newL);

        s = head;
        while(newL != NULL){
            if(newL->val != s->val)return false;
            s = s->next;
            newL = newL ->next;
        }

        return true;

    }
};