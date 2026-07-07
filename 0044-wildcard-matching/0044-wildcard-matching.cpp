class Solution {
public:

bool helper(string& s, string& p , int n , int m , int i , int j, vector<vector<int>>& dp){
    if(j == m) return (i==n);

    if(dp[i][j] != -1) return dp[i][j];

    bool f_char = false;
    if((i<n) && (s[i]==p[j] || p[j]=='?')) f_char = true;

    if(j<m && p[j]=='*'){
        bool t = (i<n) && helper(s, p, n, m, i + 1, j, dp);
        bool nt = helper(s, p, n, m, i, j + 1, dp);

        return dp[i][j] = t || nt;
    }
    return dp[i][j] = f_char && helper(s, p, n, m, i+1, j+1, dp);
}
    bool isMatch(string s, string p) {
        
        int n = s.size() , m = p.size();

        vector<vector<int>> dp(n+1, vector<int>(m+1 , -1));
        return helper(s, p, n, m , 0, 0, dp);
    }
};