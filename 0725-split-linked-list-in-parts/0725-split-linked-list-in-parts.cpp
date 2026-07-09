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
        
        vector<ListNode*>res;
        if(k == 0){
            res.push_back(head);
            return res;
        }

        ListNode* temp = head;
        int n = 0;
        while(temp){
            temp = temp->next;
            n++;
        }

        int no_ele = n/k;
        int  extra_ele = n%k;

        temp = head;
        
        for(int i =1;i<=k;i++){

            ListNode* curr_h = temp;
            
            int curr_size = no_ele;
            if(extra_ele > 0){
                curr_size +=1;
                extra_ele--;
            }

            int c=1;
            while(temp && c!= curr_size){
                temp = temp->next;
                c++;
            }

            if(temp){
                ListNode* Ntemp = temp->next;
                temp->next = NULL;
                temp = Ntemp;
            }
            res.push_back(curr_h);

        }
        return res;
    }
};