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

void helper(TreeNode* root, vector<int>& res){

    queue<TreeNode*>q;

    q.push(root);
    while(!q.empty()){

        int sz = q.size();
        vector<int>curr;

        for(int i=0;i<sz;i++){

            TreeNode* t = q.front();
            q.pop();

            curr.push_back(t->val);

            if(t->left) q.push(t->left);
            if(t->right) q.push(t->right);
        }
        res.push_back(curr.back());
    }
}
    vector<int> rightSideView(TreeNode* root) {
        
        vector<int>res;
        if(root == NULL) return res;

        helper(root, res);
        return res;
    }
};