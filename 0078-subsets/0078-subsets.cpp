class Solution {
public:
void helper(vector<vector<int>>& res, vector<int>& curr, vector<int>& nums, int n , int start){
   
    res.push_back(curr);
    for(int i=start;i<n ;i++){
        curr.push_back(nums[i]);
        helper(res, curr, nums, n , i+1);
        curr.pop_back();
    }
}
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>res;
        vector<int>curr;
        int n = nums.size();

        helper(res , curr , nums , n , 0);
        return res;
    }
};