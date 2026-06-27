class Solution {
public:

void helper(vector<int>& nums, int n , vector<vector<int>>& res, vector<int>curr , int idx){
    res.push_back(curr);

    for(int i = idx;i<n;i++){
        if(i>idx && nums[i]==nums[i-1])continue;
        curr.push_back(nums[i]);
        helper(nums, n , res, curr, i+1);
        curr.pop_back();
    }
}
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>>res;
        vector<int>curr;

        int n = nums.size();
        if(n==0)return res;

        sort(nums.begin() , nums.end());
        helper(nums , n , res, curr, 0);
        return res;
    }
};