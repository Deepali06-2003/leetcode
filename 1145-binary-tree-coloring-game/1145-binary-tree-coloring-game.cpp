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

TreeNode* findX(TreeNode* root, int x){
    if(root==NULL) return NULL;

    if(root->val == x) return root;
    TreeNode* lh = findX(root->left, x);
    if(lh) return lh;
    TreeNode* rh = findX(root->right, x);
    return rh;
}

int countNode(TreeNode* root){
    if(root == NULL)return 0;
    return 1+ countNode(root->left) + countNode(root->right);
}
    bool btreeGameWinningMove(TreeNode* root, int n, int x) {
        
        if(root == NULL) return false;

        TreeNode* temp = findX(root, x);

        int lh = countNode(temp->left);
        if(lh > (n/2) ) return true;

        int rh = countNode(temp->right); 
        if(rh > (n/2) ) return true;

        if( (n-lh-rh-1) > (n/2) ) return true;
        return false;
    }
};