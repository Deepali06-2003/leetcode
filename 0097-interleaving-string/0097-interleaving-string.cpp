class Solution {
public:

bool helper(string& s1, string& s2, string& s3 ,vector<vector<int>>& dp  , int i, int j , int n , int m){

    if( i == n && j == m && (n+m)==s3.size()) return true;

    if((i+j)>= s3.size()) return false;
    if(dp[i][j] != -1)return dp[i][j];

    bool ans = false;

    if(s1[i] == s3[i+j]) ans = helper(s1 , s2 , s3 , dp , i+1 , j , n , m);
    if(ans) return dp[i][j] = true;
    if(s2[j] == s3[i+j]) ans = helper(s1 , s2 , s3 , dp , i , j+1 , n , m);

    return dp[i][j] = ans;
}
    bool isInterleave(string s1, string s2, string s3) {
        
        int n = s1.size();
        int m = s2.size();

        if((n+m) != s3.size()) return false;

        vector<vector<int>>dp(n+1 , (vector<int>(m+1, -1)));

        return helper(s1 , s2 , s3 , dp , 0 , 0 , n , m);
    }
};