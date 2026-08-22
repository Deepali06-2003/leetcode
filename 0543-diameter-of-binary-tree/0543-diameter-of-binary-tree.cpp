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
int helper(TreeNode* root, int& ans){
    if(root == NULL) return 0;

    int lh = helper(root->left, ans);
    int rh = helper(root->right, ans);

    ans = max(ans, lh+rh);
    return max(lh, rh)+1;
}
    int diameterOfBinaryTree(TreeNode* root) {
        if(root == NULL) return 0;

        int ans = INT_MIN;
        helper(root, ans);
        return ans;
    }
};