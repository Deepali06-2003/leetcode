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
void helper(TreeNode* root , vector<int>& ans){
    if(root == NULL)return;

    helper(root->left, ans );

    ans.push_back(root->val);

    helper(root->right , ans);
}
TreeNode* findNode(TreeNode* root , int val){
    if(root == NULL) return NULL;

    if(root->val == val) return root;

    TreeNode* left = findNode(root->left, val);
    if(left) return left;

    return findNode(root->right, val);
}


    void recoverTree(TreeNode* root) {
        
        if(root == NULL)return;
        if(root->left == NULL && root->right == NULL) return;

        vector<int>ans;
        helper(root , ans);

        vector<int>temp = ans;
        sort(temp.begin(), temp.end());

        vector<int>v_swapped;
        for(int i=0 ;i<temp.size(); i++){
            if(temp[i] != ans[i]) v_swapped.push_back(ans[i]);
        }

        TreeNode* f_node = findNode(root , v_swapped[0]);
        TreeNode* s_node = findNode(root , v_swapped[1]);
        swap(f_node->val , s_node->val);

    }
    
    


};

/*
//find ele in ans which are not in sorted order
        int prev = ans[0];
        int i=1;
        while( i<ans.size() && prev < ans[i]){
            prev = ans[i];
            i++;
        }
        int f_ele = prev , s_ele = ans[i];

        TreeNode* f_eleA = findNode(root , f_ele);
        TreeNode* s_eleA = findNode(root , s_ele);
        swap(f_eleA->val , s_eleA->val)
*/