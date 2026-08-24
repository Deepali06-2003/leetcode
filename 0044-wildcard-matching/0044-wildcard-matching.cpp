class Solution {
public:

bool helper(const string& s, const string& p, int n , int m, vector<vector<int>>& dp, int i, int j){
        if(j==m)
            return (i==n);
        
        if(dp[i][j] != -1) return dp[i][j];

        bool f_char = false;
        if(i<n && (p[j]=='?' || s[i]==p[j] ) ) f_char = true;

        if(j<m && p[j]=='*'){
            bool t = (i<n) && helper(s, p, n , m , dp, i+1, j);
            bool ntake = helper(s, p, n , m , dp, i, j+1);

            return dp[i][j] = t || ntake;
        }
        return  dp[i][j] = f_char && helper(s, p, n,m, dp, i+1, j+1);
}

    bool isMatch(string s, string p) {
        int n = s.size() , m = p.size();

        vector<vector<int>>dp(n+1, vector<int>(m+1 , -1));
        return helper(s, p, n, m, dp, 0, 0);
    }
};