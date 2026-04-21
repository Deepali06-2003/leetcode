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
TreeNode* helper(vector<int>& preorder,int pre_s , int pre_e, vector<int>& postorder , int post_s , int post_e){

   if(pre_s > pre_e || post_s > post_e) return NULL;

   TreeNode* root = new TreeNode(preorder[pre_s]);

   if(pre_s == pre_e) return root;

   int left_idx = post_s;
   while(left_idx< post_e && preorder[pre_s+1] != postorder[left_idx]) left_idx++;

   int left_size = left_idx- post_s+1;

   root->left = helper(preorder, pre_s+1 , pre_s+ left_size , postorder , post_s, left_idx);
   root->right = helper(preorder, pre_s+left_size+1 , pre_e, postorder , left_idx+1, post_e-1);

   return root;
}
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        if(preorder.size() == 0)return NULL;

        TreeNode* root = helper(preorder , 0 , preorder.size()-1 , postorder , 0 , postorder.size()-1);

        return root;
    }
};