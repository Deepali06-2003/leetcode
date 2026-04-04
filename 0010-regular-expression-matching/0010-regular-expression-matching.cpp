class Solution {
public:
int n , m;

bool helper(string& s ,string& p ,vector<vector<int>>& dp, int i , int j){

    if(j == m){
        return (i == n);
    }

    if(dp[i][j] != -1)return dp[i][j];

    bool f_char = false;
    if(i<n && (s[i] == p[j] || p[j]=='.')) f_char = true;

    if(j+1 < m && p[j+1] == '*'){
        bool take = f_char && helper(s , p , dp , i+1, j);
        bool n_take = helper(s , p , dp , i , j+2);

        return dp[i][j] = take || n_take;
    }
    return dp[i][j] = f_char && helper(s , p , dp , i+1, j+1);

}

    bool isMatch(string s, string p) {
        n = s.size() , m = p.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1 , -1));
        return helper(s , p,dp, 0 , 0);
    }
};