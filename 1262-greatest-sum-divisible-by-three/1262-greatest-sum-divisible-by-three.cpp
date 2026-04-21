class Solution {
public:



    int maxSumDivThree(vector<int>& nums) {
        int n = nums.size();
    vector<vector<int>> dp(n + 1, vector<int>(3, -1e9));

    dp[n][0] = 0;  // base

    for (int i = n - 1; i >= 0; i--) {
        for (int mod = 0; mod < 3; mod++) {
            int take = nums[i] + dp[i + 1][(mod + nums[i]) % 3];
            int skip = dp[i + 1][mod];
            dp[i][mod] = max(take, skip);
        }
    }

    return dp[0][0];
       
    }
};