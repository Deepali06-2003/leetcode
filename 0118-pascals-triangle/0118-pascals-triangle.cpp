class Solution {
public:
    vector<vector<int>> generate(int numRows) {
    int n = numRows;

    vector<vector<int>> dp(numRows, vector<int>(numRows, 0));
    vector<vector<int>>res;
    vector<int>temp;


    for(int i=0;i<n;i++)dp[i][0]=1;
    res.push_back({1});

    for(int i =1;i<n;i++){
        temp.clear();
        temp.push_back(1);

        for(int j=1;j<=i; j++){

            if(i == j) dp[i][j] = 1;
            else dp[i][j] = dp[i-1][j] + dp[i-1][j-1];
            temp.push_back(dp[i][j]);
        }
        res.push_back(temp);
    }


    return res;
    }
};