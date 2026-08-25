class Solution {
public:
    int numTrees(int n) {
        if(n==0 || n==1) return 1;

        vector<int>dp(n+1, 0);
        dp[0]= dp[1]=1;
        
        for(int i = 2;i<=n;i++){
            for(int r =1;r<=i;r++){
                dp[i] = dp[i] + (dp[r-1]*dp[i-r]);
            }
        }
        return dp[n];
    }
};