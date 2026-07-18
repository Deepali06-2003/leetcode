class Solution {
public:
void helper(vector<int>& candidates, int target, vector<vector<int>>& res, vector<int>& curr ,int n, int idx){
    if(target == 0){
        res.push_back(curr);
        return;
    }

    if(idx == n || target < 0) return;

    for(int i = idx ;i<n ; i++){
        if(i>idx && candidates[i] == candidates[i-1]) continue;
        curr.push_back(candidates[i]);
        helper(candidates , target-candidates[i] , res, curr , n , i+1);
        curr.pop_back();
    }
}
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        
        int n = candidates.size();
        sort(candidates.begin(), candidates.end());
        vector<vector<int>>res;
        vector<int>curr;

        helper(candidates , target , res, curr,n, 0);
        return res;
    }
};