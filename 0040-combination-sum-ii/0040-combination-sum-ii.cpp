class Solution {
public:
void helper(vector<int>& candidates, int target, vector<vector<int>>& res, vector<int>& curr , int idx){
    if(target == 0){
        res.push_back(curr);
        return;
    }
    if(target<0 || idx == candidates.size()) return;

    for(int i = idx ;i<candidates.size();i++){
        if(i>idx && candidates[i] ==candidates[i-1])continue;
        curr.push_back(candidates[i]);
        helper(candidates, target-candidates[i] , res, curr, i+1);
        curr.pop_back();
    }
}
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        
        int n = candidates.size();
        sort(candidates.begin(), candidates.end());
        vector<vector<int>>res;
        vector<int>curr;

        helper(candidates , target , res, curr, 0);
        return res;
    }
};