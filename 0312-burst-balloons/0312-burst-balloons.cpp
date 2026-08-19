class Solution {
public:

int helper(vector<int>& nums, int l, int r, vector<vector<int>>& dp){
    if(l>r) return 0;
    if(dp[l][r] != -1) return dp[l][r];

    int ans = INT_MIN;
    for(int x=l;x<=r;x++){
        int curr = nums[x] * nums[l-1] * nums[r+1];
        curr = curr + helper(nums, l, x-1, dp) + helper(nums, x+1, r, dp);

        ans = max(ans, curr);
    }
    return dp[l][r]=ans;
}
    int maxCoins(vector<int>& nums) {
        
        int n = nums.size();
        nums.push_back(1);
        nums.insert(nums.begin(), 1);

        vector<vector<int>>dp(n+1, vector<int>(n+1, -1));
        return helper(nums, 1, n, dp);
    }
};