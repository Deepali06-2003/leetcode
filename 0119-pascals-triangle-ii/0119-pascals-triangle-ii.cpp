class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int>ans;

        vector<vector<int>>dp(rowIndex+1, vector<int>(rowIndex+1,0));

        for(int i=0;i<=rowIndex;i++)dp[i][0]=1;

        for(int i=1;i<=rowIndex;i++){
            for(int j = 1;j<=rowIndex;j++){

                if(i==j)dp[i][j]=1;
                else dp[i][j] = dp[i-1][j]+ dp[i-1][j-1];
            }
        }

        return dp[rowIndex];
    }
};