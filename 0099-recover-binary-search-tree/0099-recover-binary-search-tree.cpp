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

TreeNode* prev=NULL;
TreeNode* f_ele=NULL;
TreeNode* s_ele=NULL;

void helper(TreeNode* root){
    if(root == NULL)return;

    helper(root->left);

    if(prev && prev->val > root->val){
        if(f_ele == NULL){
            f_ele = prev;
            s_ele = root;
        }
        else s_ele = root;
    }
    
    prev = root;
    helper(root->right);
}
    void recoverTree(TreeNode* root) {
        
        if(root == NULL) return;

        helper(root);
        swap(f_ele->val , s_ele->val);
    }
};