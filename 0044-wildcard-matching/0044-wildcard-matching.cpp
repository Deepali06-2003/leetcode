class Solution {
public:

bool helper(string& s, string& p,vector<vector<int>>& dp, int n , int m ,int i, int j ){
    if(j==m){
        return i==n;
    }
    if(dp[i][j]!=-1)return dp[i][j];

    if(j<m && p[j]=='*'){
        bool take = (i<n) && helper(s,p,dp, n , m, i+1, j);
        bool n_take = helper(s, p, dp,n, m , i, j+1);
        return dp[i][j] = take||n_take;
    }
    
    bool f_char = ( (i<n) && ((s[i]==p[j]) || (p[j]=='?')) );
    return dp[i][j] = f_char && helper(s,p, dp,n, m, i+1,j+1);
    

}
    bool isMatch(string s, string p) {
        
        int n = s.size(), m =p.size();
        vector<vector<int>>dp(n+1, vector<int>(m+1, -1));
        return helper(s, p , dp , n , m , 0 , 0);
    }
};