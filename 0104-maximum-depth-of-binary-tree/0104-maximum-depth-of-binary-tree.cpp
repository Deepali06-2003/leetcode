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
int helper(TreeNode* root, int& ans, int c){
    if(root == NULL) return 0;

    ans = max(ans, c);

    int lh = helper(root->left, ans, c);
    int rh = helper(root->right, ans, c);

    return  max(lh, rh)+1;
}
    int maxDepth(TreeNode* root) {
        if(root == NULL) return 0;

        int ans = INT_MIN;
        return helper(root , ans , 0);
        
    }
};