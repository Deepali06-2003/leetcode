class Solution {
public:

int helper(vector<int>& nums, int l , int h, vector<vector<int>>& dp){

    if(l>h)return 0;
    if(dp[l][h] != -1) return dp[l][h];
    int ans = INT_MIN;

    for(int i=l;i<=h;i++){
        int x = nums[l-1] * nums[i] * nums[h+1];
        x = x+ helper(nums, l, i-1, dp) + helper(nums, i+1, h, dp);
        ans = max(ans, x);
    }
    return dp[l][h] = ans;
}
    int maxCoins(vector<int>& nums) {
        
        int n = nums.size();

        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        
        vector<vector<int>> dp (n+1, vector<int>(n+1, -1));
        return helper(nums, 1, n, dp);
    }
};