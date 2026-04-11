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
    ListNode* prev = NULL;
    while(head!=NULL){
        ListNode* n_head = head->next;
        head->next = prev;

        prev = head;
        head = n_head;
    }
    return prev;
}

ListNode* get_k(ListNode* temp , int k){

    k= k-1;
    while(temp!= NULL && k>0){
        k--;
        temp = temp->next;
    }
    return temp;
}
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head == NULL || k<=0)return head;

        ListNode* temp = head;
        ListNode* new_head = new ListNode(0);
        ListNode* t_new = new_head;

        while(temp != NULL){

            ListNode* k_node = get_k(temp , k);
            if(!k_node) break;
            ListNode* nextTemp = k_node->next;
            k_node->next = NULL;

            t_new->next = reverse(temp);
            t_new = temp;
            temp->next = nextTemp;
            temp = nextTemp;

        }

        return new_head->next;

    }
};


