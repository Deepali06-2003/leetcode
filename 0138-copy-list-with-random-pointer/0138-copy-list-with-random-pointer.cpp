/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == NULL)return NULL;

        unordered_map<Node* , Node*>mp;
       
        Node* newH = new Node(head->val);
        Node* nt = newH;
        Node* t = head->next;
        mp[head] = newH;

        while(t){
            nt->next = new Node(t->val);
            nt = nt->next;
            mp[t] = nt;
            t = t->next;
        }
        t = head;
        nt = newH;

        while(t){
            if(mp.find(t->random) != mp.end())
                nt->random = mp[t->random];
            nt = nt->next;
            t = t->next;
        }
        return newH;
    }
};