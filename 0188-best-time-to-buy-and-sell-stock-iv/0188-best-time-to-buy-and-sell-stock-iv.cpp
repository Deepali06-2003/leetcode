class Solution { //buy = 1
public:
    int maxProfit(int k, vector<int>& prices) {
        
        int n = prices.size();

       vector<vector<vector<int>>>dp(n+1 , vector<vector<int>>(2, vector<int>(k+1 , 0)));

        for(int i=n-1 ; i>=0 ; i--){
            for(int b = 0 ; b<=1 ; b++){
                for(int c=1; c<=k ; c++ ){

                    if(b == 1){
                        dp[i][b][c] = max( -prices[i]+ dp[i+1][0][c] , 0 +dp[i+1][1][c]);
                    }
                    else{
                        dp[i][b][c] = max( prices[i]+dp[i+1][1][c-1] , 0+dp[i+1][0][c]);
                    }
                }
            }
        }


       return dp[0][1][k];
       
    }
};