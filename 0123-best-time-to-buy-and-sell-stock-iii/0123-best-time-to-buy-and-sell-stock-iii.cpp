class Solution {
public:
int helper(vector<int>& prices ,vector<vector<vector<int>>>& dp , int i , int buy , int c ){

    int n = prices.size();
    if(i == n || c ==0)return 0;
    
    if(dp[i][buy][c] != -1)return dp[i][buy][c];

    //buy
    if(buy == 1){                        // 0->means not allowed to buy anything            i can buy anything
        return dp[i][buy][c] = max(  (-prices[i]+helper(prices , dp , i+1 , 0 , c)) ,
                                      (0+ helper(prices, dp , i+1, 1, c))  );
    }
    //sell
    else{                              //i have sell it and capacity will reduce        didnot sell so can't buy
        return dp[i][buy][c] =  max( (prices[i]+helper(prices, dp , i+1, 1, c-1)) , 
                                    (0+ helper(prices, dp , i+1, 0 , c)) );
    }
}
    int maxProfit(vector<int>& prices) {
        
       int n = prices.size();

       vector<vector<vector<int>>> dp (n , vector<vector<int>> (2, vector<int>(3, -1) ) );

       return helper(prices , dp , 0 , 1, 2);

    }
};