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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*>ans;
        if(k==0){ ans.push_back(head); return ans;}

        ListNode* temp = head;
        int c=0;
        while(temp != NULL){
            c++;
            temp = temp->next;
        }

        int ele_grp = c/k;
        int ele_e = c%k;
        temp = head;

        for(int i=0;i<k;i++){
            
            int ele = ele_grp ;
            if(ele_e > 0){
                 ele += 1;
                ele_e--;}

            ListNode* h = NULL;
            if(temp != NULL){
                h = temp;
                while(temp!=NULL && ele!=1){
                    temp  = temp->next;
                    ele--;
                }
                ListNode* t = temp;
                if(temp != NULL){
                    temp = temp->next;
                    t->next = NULL;}
            }
            ans.push_back(h);
        }
        return ans;
    }
};