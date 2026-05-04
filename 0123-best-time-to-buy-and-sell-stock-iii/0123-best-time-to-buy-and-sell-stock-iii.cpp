class Solution {
public:


    int maxProfit(vector<int>& prices) {

       int n = prices.size();

       vector<vector<vector<int>>> dp (n+1 , vector<vector<int>> (2, vector<int>(3, 0))) ;
       
       for(int i=n-1 ; i>=0 ; i--){
            for(int b=0 ; b<=1 ; b++){

                for(int c=1 ; c<=2 ; c++){
                    //buy
                    if(b == 1){                       
                         // 0->means not allowed to buy anything        i can buy anything
                        dp[i][b][c] = max(  -prices[i]+ dp[i+1][0][c] , 0+dp[i+1][1][c]   );
                    }
                    //sell
                    else{           
                          //i have sell it and capacity will reduce   didnot sell so can't buy
                        dp[i][b][c] = max(  prices[i]+ dp[i+1][1][c-1] , 0+dp[i+1][0][c]   );
                    }
                }
            }
       }
       return dp[0][1][2];
    }
};