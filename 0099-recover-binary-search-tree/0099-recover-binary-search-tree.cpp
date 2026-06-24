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

TreeNode* first_ele = NULL;
TreeNode* second_ele = NULL;
TreeNode* prev = NULL;

void helper(TreeNode* root ){
    if(root == NULL)return;

    helper(root->left);
    // link is broken
    if(prev && prev->val > root->val) {

            if(first_ele == NULL) {
                first_ele = prev;
                second_ele = root;
            }
            else {
                second_ele = root;
            }
        }

        prev = root;

    helper(root->right);
}

    void recoverTree(TreeNode* root) {
        
        if(root == NULL)return;
        if(root->left == NULL && root->right == NULL) return;

        helper(root);
        
        swap(first_ele->val , second_ele->val);
    }
};

