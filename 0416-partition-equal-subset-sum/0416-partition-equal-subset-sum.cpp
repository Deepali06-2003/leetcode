class Solution {
public:
    bool canPartition(vector<int>& nums) {
        
        int n = nums.size();
        int s =0;
        for(int i: nums) s= s+i;

        if(s%2!=0) return false;

        int target = s/2;

        vector<vector<unsigned long long>> dp(n+1, vector<unsigned long long>(target+1, 0));

        for(int i =0;i<=n;i++) dp[i][0]=1;

        for(int i=1;i<=n;i++){
            for(int j=1;j<=target;j++){

                if(nums[i-1] > j) dp[i][j] = dp[i-1][j];
                else dp[i][j] = dp[i-1][j] + dp[i-1][j- nums[i-1]];
            }
        }

        return dp[n][target];


    }
};