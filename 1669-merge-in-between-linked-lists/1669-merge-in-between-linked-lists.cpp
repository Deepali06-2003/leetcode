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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        
        ListNode* temp = list1;
        for(int i=1;i<a;i++){
            temp = temp->next;
        }
        ListNode* first = temp;

        temp = temp->next;
        for(int i = 0;i<(b-a);i++){
            temp = temp->next;
        }
        temp = temp->next;

        ListNode* c = list2;
        while(c->next){
            c= c->next;
        }
        first->next = list2;
        c->next = temp;

        return list1;
    }
};