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

int c=0;
unordered_map<long, int>mp;

void helper(TreeNode* root, int targetSum, long s){
    if(root == NULL)return;

    s = s+ root->val;
    if(targetSum == s)c++;

    if(mp.find(s-targetSum) != mp.end()) c = c+ mp[s-targetSum];

    mp[s]++;
    helper(root->left, targetSum , s);
    helper(root->right, targetSum , s);
    mp[s]--;
}
    int pathSum(TreeNode* root, int targetSum) {
        helper(root, targetSum , 0);
        return c;
    }
};