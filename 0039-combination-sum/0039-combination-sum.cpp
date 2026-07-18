class Solution {
public:

void helper(vector<int>& candidates, int target, vector<vector<int>>& res, vector<int> curr, int n , int idx){
    if(0 == target){
        res.push_back(curr);
        return;
    }

    if(idx == n || target < 0) return;

    curr.push_back(candidates[idx]);
    helper(candidates, target-candidates[idx] , res, curr, n , idx);
    curr.pop_back();

    helper(candidates, target , res, curr, n , idx+1);
}
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int n = candidates.size();
        sort(candidates.begin(), candidates.end());

        vector<vector<int>>res;
        vector<int>curr;

        helper(candidates, target, res, curr, n , 0);
        return res;
    }
};