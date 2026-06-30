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

int helper(TreeNode* root){
    if(root == NULL) return 0;
    return 1 + helper(root->left) + helper(root->right);
}

TreeNode* findX(TreeNode* root, int x){
    if(root== NULL) return NULL;
    if(root->val == x)return root;

    TreeNode* lh = findX(root->left, x);
    if(lh) return lh;
    TreeNode* rh = findX(root->right, x);
    return rh;
}
    bool btreeGameWinningMove(TreeNode* root, int n, int x) {
        
        TreeNode* temp =findX(root, x);
        if(temp == NULL)return false;

        int lh = helper(temp->left);
        if(lh > (n/2)) return true;

        int rh = helper(temp->right);
        if(rh>(n/2)) return true;

        if( (n - (lh+rh+1)) > (n/2) ) return true;

        return false;
    }
};