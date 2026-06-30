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
    ListNode* swapNodes(ListNode* head, int k) {
        if(head == NULL || k==0) return head;

        ListNode* temp = head;
        int c =0;
        while(temp){
            c++;
            temp = temp->next;
        }
        int l_node = c-k;

       
        ListNode* curr1=head;
        ListNode* curr2 = head;
        

        while(curr1 && k!=1){
            k--;
            curr1 = curr1->next;
        }
        while(curr2 && l_node!=0){
            l_node--;
            curr2 = curr2->next;
        }
        swap(curr1->val , curr2->val);
        return head;
    }
};