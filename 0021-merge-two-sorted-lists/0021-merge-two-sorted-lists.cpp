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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        
        ListNode* n_temp = new ListNode(0);
        ListNode* t = n_temp;

        if(list1==NULL && list2==NULL) return NULL;
        if(list1 == NULL) return list2;
        if(list2 == NULL) return list1;

        while(list1 && list2){
            if(list1->val <= list2->val){
                t->next = list1;
                list1 = list1->next;
            }
            else{
                t->next = list2;
                list2 = list2->next;
            }
             t = t->next;
        }
        if(list1) t->next = list1;
        if(list2) t->next = list2;

        return n_temp->next;
    }
};