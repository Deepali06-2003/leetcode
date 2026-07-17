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
    if(head==NULL || head->next == NULL) return head;

    ListNode* curr = head;
    ListNode* n_curr = NULL;
    ListNode* prev = NULL;

    while(curr != NULL){
        n_curr = curr ->next;
        curr->next = prev;

        prev = curr;
        curr = n_curr;
    }
    return prev;
}

    bool isPalindrome(ListNode* head) {
        
        if(head == NULL || head->next==NULL) return true;

        ListNode* s = head;
        ListNode* f = head;

        while(f->next!= NULL && f->next->next != NULL){
            s = s->next;
            f = f->next->next;
        }

        ListNode* h1 = head;
        ListNode* h2 = s->next;
        s->next = NULL;
        h2 = reverse(h2);

        while(h2 != NULL){
            if(h1->val != h2->val) return false;

            h1 = h1->next;
            h2 = h2->next;
        }

        return true;
    }
};