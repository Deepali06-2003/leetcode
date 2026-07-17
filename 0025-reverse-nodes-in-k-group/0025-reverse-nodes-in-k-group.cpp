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
ListNode* KthNode(ListNode* head, int k){
    if(head == NULL || k==0) return NULL;
    k--;
    while(head != NULL && k!=0){
        k--;
        head = head->next;
    }
        
    return head;
}

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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head == NULL || k<=0) return head;

        ListNode* n_head = new ListNode(0);
        ListNode* nTemp = n_head;

        ListNode* temp = head;
        while(temp){

            ListNode* k_n = KthNode(temp, k);
            if(!k_n) break;

            ListNode* t_n = k_n->next;
            k_n->next = NULL;

            nTemp->next = reverse(temp);

            nTemp = temp;
            temp->next = t_n;
            temp = t_n;
        }
       return n_head->next;
    }
};