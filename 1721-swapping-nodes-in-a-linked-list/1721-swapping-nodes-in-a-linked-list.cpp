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
        while(temp && k!=1){
            k--;
            temp = temp->next;
        }
        ListNode* curr1 = temp;
        temp = temp->next;
        ListNode* curr2 = head;
        while(temp){
            temp= temp->next;
            curr2 = curr2->next;
        }
        swap(curr1->val , curr2->val);
        return head;
    }
};