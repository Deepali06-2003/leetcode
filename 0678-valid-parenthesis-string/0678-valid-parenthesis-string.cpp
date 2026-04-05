class Solution {
public:

bool helper(string& s , int& n , vector<vector<int>>& dp, int i , int c){

    if(c<0) return false;
    if(i == n) return (c==0);

    if(dp[i][c] != -1)return dp[i][c];

    if(s[i] == '(') return dp[i][c] = helper(s , n , dp , i+1 , c+1);
    else if(s[i] == ')') return dp[i][c] = helper(s , n , dp , i+1 , c-1);

    return dp[i][c] = (helper(s , n , dp , i+1 , c+1) || helper(s , n , dp , i+1 , c-1) || helper(s , n , dp , i+1 , c));
}
    bool checkValidString(string s) {
        int n = s.size();
        vector<vector<int>> dp(n+1 , vector<int>(n+1 , -1));

        return helper(s , n, dp , 0 , 0);
    }
};