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
bool helper(TreeNode* r_l , TreeNode* r_r){

    if(r_l == NULL && r_r==NULL) return true;
    if(r_l==NULL || r_r==NULL) return false;
    if(r_l->val != r_r->val) return false;

    return helper(r_l->left , r_r->right) && helper(r_r->left , r_l->right);
}
    bool isSymmetric(TreeNode* root) {
        
        return helper(root->left , root->right);
    }
};