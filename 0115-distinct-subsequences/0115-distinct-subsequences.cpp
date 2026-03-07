class Solution {
public:

long long solve(int i,int j,string &s,string &t,int n,int m,vector<vector<long long>>&dp){

    if(j == m) return 1;
    if(i == n) return 0;
    if(n - i < m - j) return 0;

    if(dp[i][j] != -1) return dp[i][j];

    if(s[i] == t[j])
        return dp[i][j] = solve(i+1,j+1,s,t,n,m,dp) + solve(i+1,j,s,t,n,m,dp);

    return dp[i][j] = solve(i+1,j,s,t,n,m,dp);
}

    int numDistinct(string s, string t) {
        int n=s.size();
        int m=t.size();
        vector<vector<long long>>dp(n,vector<long long>(m,-1));
        return solve(0,0,s,t,n, m , dp);
    }
};