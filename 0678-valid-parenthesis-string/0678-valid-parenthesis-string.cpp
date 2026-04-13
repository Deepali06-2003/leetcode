class Solution {
public:
bool helper(string& s ,  int c, int i, vector<vector<int>>& dp){
   
    if(i == s.size()) return (c==0);
    if(c < 0) return false;
    if(dp[i][c] != -1)return dp[i][c];

    if(s[i] =='(') return dp[i][c] = helper(s, c+1 , i+1, dp);
    else if(s[i] == ')') return dp[i][c] =helper(s, c-1 , i+1, dp);

    else return dp[i][c] = ( helper(s, c+1 , i+1, dp) || helper(s, c-1 , i+1, dp) || helper(s, c , i+1, dp) );
}


    bool checkValidString(string s) {
        int n = s.size();
        vector<vector<int>>dp(n+1, vector<int>(n+1, -1));
        return helper(s, 0, 0, dp);
    }
};