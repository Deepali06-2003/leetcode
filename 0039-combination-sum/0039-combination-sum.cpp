class Solution {
public:

void helper(vector<int>& candidates, int target, vector<vector<int>>&res, vector<int> curr, int idx){

    if(0 == target){
        res.push_back(curr);
        return;
    }
    if(target<0 || idx==candidates.size()) return;
     
    curr.push_back(candidates[idx]);
    helper(candidates, target-candidates[idx] , res, curr, idx);
    curr.pop_back();

    helper(candidates, target , res, curr, idx+1);
}
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>res;
        vector<int>curr;
        helper(candidates, target , res, curr, 0);
        return res;
    }
};