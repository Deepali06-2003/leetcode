/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

void helper(TreeNode* root, vector<int>& res, vector<int>curr){
    if(root == NULL)return;
    
    queue<TreeNode*>q;
    q.push(root);

    while(!q.empty()){
        curr.clear();
        int s = q.size();

        for(int i=0;i<s;i++){
            TreeNode* t = q.front();
            q.pop();
            
            curr.push_back(t->val);

            if(t->left) q.push(t->left);
            if(t->right) q.push(t->right);
        }
        sort(curr.begin() , curr.end());
        res.push_back(curr[curr.size()-1]);
    }
}

    vector<int> largestValues(TreeNode* root) {
        vector<int>res;
        vector<int>curr;

        helper(root, res, curr);
        return res;
    }
};