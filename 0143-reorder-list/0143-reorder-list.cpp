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
    ListNode* n_curr=NULL;

    while(curr){
        n_curr = curr->next;

        curr->next = prev;
        prev = curr;
        curr = n_curr;
    }
    return prev;
}
    void reorderList(ListNode* head) {
        
        ListNode* s = head;
        ListNode* f = head;

        while(f!=NULL && f->next!=NULL){
            s=s->next;
            f=f->next->next;
        } 

        ListNode* temp = s->next;
        s->next = NULL;

        temp = reverse(temp);
        s = head;

        while(temp!= NULL){

            ListNode* c1 = s->next;
            ListNode* c2 = temp->next;
            s->next = temp;
            temp->next = c1;

            s = c1;
            temp = c2;
        }
    }
};