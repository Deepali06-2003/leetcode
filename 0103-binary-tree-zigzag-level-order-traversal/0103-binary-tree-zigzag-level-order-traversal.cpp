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
int flag = 1;

void helper(TreeNode* root , vector<vector<int>>& res, vector<int>& curr){
    if(root == NULL) return;
    queue<TreeNode*>q;

    q.push(root);

    while(!q.empty()){

        curr.clear();
        int s = q.size();

        for(int i =0;i<s;i++){
            TreeNode* x = q.front();
            q.pop();

            curr.push_back(x->val);
            if(x->left) q.push(x->left);
            if(x->right) q.push(x->right);
        }
        if(flag == 1){
            res.push_back(curr);
            flag =0;
        }
        else{
            reverse(curr.begin(), curr.end());
            res.push_back(curr);
            flag =1;
        }
        
    }
}

    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>res;
        vector<int>curr;

        helper(root, res, curr);
        return res;
    }
};