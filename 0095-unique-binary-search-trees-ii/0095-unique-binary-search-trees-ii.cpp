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
vector<TreeNode*> helper( int s, int e){

    if(s>e) return {NULL};

    vector<TreeNode*> res;
    for(int i=s;i<=e;i++){

        vector<TreeNode*> ls = helper(s, i-1);
        vector<TreeNode*> rs = helper( i+1, e);

        for(auto l : ls){
            for(auto r : rs){
                TreeNode* root = new TreeNode(i);
                root->left = l;
                root->right = r;

                res.push_back(root);
            }
        }        
    }
    return res;
}
    vector<TreeNode*> generateTrees(int n) {

        vector<TreeNode*>res;
        if(n==0) return res;

        res = helper(1, n);
        return res;
    }
};