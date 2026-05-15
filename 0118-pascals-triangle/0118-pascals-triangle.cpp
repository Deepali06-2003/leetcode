class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        
        int n = numRows;
        vector<vector<int>> dp(n, vector<int>(n, 0));

        for(int i =0;i<n;i++) dp[i][0] =1;

        for(int i =1;i<n;i++){
            for(int j = 1;j<n;j++){

                if(i == j) dp[i][j] =1;
                else dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
            }
        }

        vector<vector<int>>res;
        vector<int>curr;

        for(int i=0;i<n;i++){
            curr.clear();

            for(int j=0;j<n;j++){
                if(dp[i][j] != 0) curr.push_back(dp[i][j]);
            }
            res.push_back(curr);
        }

        return res;
    }
};