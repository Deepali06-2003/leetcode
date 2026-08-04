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

void helper(TreeNode* root, unordered_map<int, int>& mp){
    if(root == NULL) return;

    helper(root->left, mp);
    mp[root->val]++;
    helper(root->right, mp);
}

    vector<int> findMode(TreeNode* root) {
        if(root == NULL) return {0};

        unordered_map<int, int> mp;
        helper(root, mp);

        int maxFreq=0;
        for (auto &p : mp)
            maxFreq = max(maxFreq, p.second);

        vector<int>ans;
        for(auto i: mp){
            if(i.second == maxFreq)ans.push_back(i.first);
        }
        return ans;

    }
};