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
TreeNode* helper(vector<int>& preorder,int ps, int pe ,vector<int>& inorder, int is, int ie){
    if(ps>pe || is>ie) return NULL;

    TreeNode* root = new TreeNode(preorder[ps]);
    int r_idx = is;
    while(r_idx<=ie && inorder[r_idx] != preorder[ps]) r_idx++;

    int left_size = r_idx - is;

    root->left = helper(preorder , ps+1 , ps+left_size , inorder , is , r_idx-1);
    root->right = helper(preorder  , ps+left_size+1, pe , inorder ,  r_idx+1, ie);

    return root;
}
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        //pre -> root , left, right
        //in -> left, root, right

        int n = preorder.size();
        return helper(preorder, 0, n-1, inorder, 0, n-1);
    }
};