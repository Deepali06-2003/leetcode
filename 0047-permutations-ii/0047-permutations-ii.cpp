class Solution {
public:
void helper(vector<vector<int>>& res, vector<int>curr,vector<int>& nums , int s, vector<bool>& used){
    if(curr.size() == nums.size()){
        res.push_back(curr);
        return;
    }
    for(int i =0;i<nums.size();i++){
        if(used[i] == true) continue;
        if(i>0 && nums[i]==nums[i-1] && used[i-1] == false) continue;

        curr.push_back(nums[i]);
        used[i] = true;
        helper(res, curr, nums, i+1, used);
        curr.pop_back();
        used[i] = false;
    }

}
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>>res;
        vector<int>curr;
       
        vector<bool>used(nums.size(), false);
        sort(nums.begin(), nums.end());

        helper(res, curr, nums, 0, used);
        return res;
    }
};