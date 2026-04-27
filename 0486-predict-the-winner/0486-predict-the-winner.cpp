class Solution {
public:
int helper(vector<int>& nums,vector<vector<int>>& dp, int l , int r){
    if(l>r)return 0;
    if(l == r)return nums[l];
    if(dp[l][r] != INT_MIN) return dp[l][r];

    int lh = nums[l]- helper(nums ,dp, l+1, r);
    int rh = nums[r] - helper(nums ,dp, l , r-1);

    return dp[l][r] = max(lh , rh);
}
    bool predictTheWinner(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>dp(n , vector<int>(n, INT_MIN));

        return helper(nums ,dp, 0 , n-1)>=0;

    }
};