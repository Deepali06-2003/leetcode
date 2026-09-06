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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        
        queue<pair<TreeNode* , pair<int,int>>>q;    //node, level , vertex
        map<int , map<int, multiset<int>>>mp;       //vertex ->level->node

        q.push({root, {0, 0}});

        while(!q.empty()){

            auto j = q.front();
            q.pop();

            int l = j.second.first;
            int v = j.second.second;

            mp[v][l].insert(j.first->val);

            if(j.first->left) q.push({j.first->left, {l+1, v-1}});
            if(j.first->right) q.push({j.first->right, {l+1, v+1}});
        }

        vector<vector<int>>res;
        for (auto &v : mp) {

            vector<int> curr;

            for (auto &l : v.second) {

                for (auto x : l.second) {
                    curr.push_back(x);
                }
            }

            res.push_back(curr);
         }
        return res;
    }
};