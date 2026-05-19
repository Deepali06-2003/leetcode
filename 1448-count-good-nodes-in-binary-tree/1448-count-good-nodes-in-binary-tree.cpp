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
int prev = INT_MIN;

void helper(TreeNode* root , int& ans, int prev){
    if(root == NULL) return;

    if(root->val >= prev){
         ans = ans+1;
         prev = root->val;
    }

    helper(root->left , ans , prev);
    helper(root->right, ans , prev);
}
    int goodNodes(TreeNode* root) {
        int ans = 0;
        int prev = INT_MIN;

        helper(root, ans , prev);
        return ans;
    }
};