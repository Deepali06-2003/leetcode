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
TreeNode* helper(vector<int>& preorder, int s, int e){
    if(s>e) return NULL;
    
    TreeNode* root = new TreeNode(preorder[s]);

    int idx = s+1;
    while(idx<=e && preorder[idx]<preorder[s]) idx++;


    root->left = helper(preorder, s+1,idx-1);
    root->right = helper(preorder, idx, e);

    return root;
}

    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int n = preorder.size();

        if(n==0) return NULL;
        return helper(preorder, 0, n-1);
    }
};