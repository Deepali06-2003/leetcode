class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int n = prices.size();

        vector<vector<vector<int>>> dp (n+1, vector<vector<int>>(2, vector<int>(3, 0)));

        for(int i =n-1;i>=0 ;i--){
            for(int b = 0;b<=1;b++){
                for(int k = 1;k<=2;k++){

                    if(b==1) dp[i][b][k] = max(-prices[i] + dp[i+1][0][k] , dp[i+1][1][k]);
                    else dp[i][b][k] = max(prices[i]+dp[i+1][1][k-1] , dp[i+1][0][k]);
                }
            }
        }

        return dp[0][1][2];
    }
};