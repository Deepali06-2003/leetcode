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

 ListNode* findMid(ListNode* head){

        ListNode* slow = head;
        ListNode* fast = head->next;

        while(fast && fast->next){

            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
}



ListNode* merge(ListNode* left, ListNode* right){

        ListNode dummy(0);
        ListNode* temp = &dummy;

        while(left && right){

            if(left->val < right->val){

                temp->next = left;
                left = left->next;
            }
            else{

                temp->next = right;
                right = right->next;
            }

            temp = temp->next;
        }

        if(left)
            temp->next = left;

        if(right)
            temp->next = right;

        return dummy.next;
    }





    ListNode* sortList(ListNode* head) {
        if(head == NULL|| head->next ==NULL) return head;
        //mid ele of ll
        ListNode* mid = findMid(head);

        // divide array into 2-parts
        ListNode* f_half = head;
        ListNode* s_half = mid->next;
        mid->next = NULL;

        //sort array
        f_half = sortList(f_half);
        s_half = sortList(s_half);
        
        return merge(f_half , s_half);
        
    }
};