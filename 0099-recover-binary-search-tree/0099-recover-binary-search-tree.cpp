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

TreeNode* prev = NULL;
TreeNode* f = NULL;
TreeNode* s = NULL;

void helper(TreeNode* root){
    if(root == NULL)return;

    helper(root->left);
    if(prev && root->val < prev->val){
        if(f==NULL){
            f = prev;
            s = root;
        }
        else s= root;
    }
    prev = root;
    helper(root->right);
}

    void recoverTree(TreeNode* root) {
        helper(root);
        swap(f->val, s->val);
    }
};