class Solution {
public:


    double champagneTower(int poured, int query_row, int query_glass) {
        
        int n = query_row;
        vector<vector<double>> dp(n+1 , vector<double>(n+1 , 0.0));
        dp[0][0] = poured;
        
        for(int i=0;i<n; i++){
            for(int j =0;j<=i ;j++){
                double temp = (dp[i][j]-1.0) / 2.0;
                if(temp > 0){
                    dp[i+1][j] += temp;
                    dp[i+1][j+1] += temp;
                }
            }
        }
        return min(dp[query_row][query_glass], 1.0);
       
    }
};
