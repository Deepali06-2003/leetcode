class Solution {
public:
void helper(vector<int>& candidates, int target,vector<vector<int>>& res, vector<int>curr, int start){

   if(target==0){
    res.push_back(curr);
    return;
   }
   if(target<0 || start == candidates.size())return;

   for(int i=start;i<candidates.size();i++){
    if(i>start && candidates[i] ==candidates[i-1])continue;
    
    curr.push_back(candidates[i]);
    helper(candidates , target-candidates[i], res, curr, i+1);
    curr.pop_back();
   }
}
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>>res;
        vector<int>curr;
        sort(candidates.begin(), candidates.end());
        helper(candidates, target , res, curr , 0);
        return res;
    }
};