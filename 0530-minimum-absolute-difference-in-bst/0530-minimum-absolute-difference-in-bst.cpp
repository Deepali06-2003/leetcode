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

int prev = 0;
int ans = INT_MAX;
int f =0;

void helper(TreeNode* root){
    if( root== NULL)return;

    helper(root->left);
    if(f == 0){
        prev = root->val;
        f = 1;
    }
    else{
         int x = root->val - prev;
        if(x < ans) ans = x;
        prev = root->val;
    }

    helper(root->right);
}

    int getMinimumDifference(TreeNode* root) {
       
        if(root == NULL)return -1;
        

        helper(root);
        return ans;
    }
};