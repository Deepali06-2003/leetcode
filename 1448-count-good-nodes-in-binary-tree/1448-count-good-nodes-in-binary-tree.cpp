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
void helper(TreeNode* root , int c , int& ans){
    if(root == NULL)return;
    if(root->val >= c){
        ans++;
        c= root->val;
    }
    helper(root->left , c, ans);
    helper(root->right , c, ans);
}
    int goodNodes(TreeNode* root) {
        if(root == NULL)return 0;
        int ans =0;
        int c = INT_MIN;
        
        helper(root , c, ans);
        return ans;
    }
};