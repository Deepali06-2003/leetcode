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
    ListNode* sortList(ListNode* head) {
        if(head == NULL|| head->next ==NULL) return head;

        ListNode* temp = head;

        vector<int>arr;
        while(temp){
            arr.push_back(temp->val);
            temp = temp->next;
        }

        sort(arr.begin(), arr.end());

        ListNode* n_head = new ListNode(0);
        ListNode* t = n_head;

        for(int i : arr){
            t->next = new ListNode(i);
            t = t->next;
        }

        return n_head->next;
        
        
    }
};