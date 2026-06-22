class Solution {
public:

bool helper(string s, vector<vector<int>>& dp ,int n , int c , int i){
    if(c<0) return false;
    if(i == n) return (c == 0);
    if(dp[i][c] != -1) return dp[i][c];

    if(s[i]=='(') return dp[i][c] = helper(s, dp , n, c+1 , i+1);
    else if(s[i]==')') return dp[i][c] = helper(s, dp , n , c-1 , i+1);
    else return dp[i][c] = helper(s, dp , n, c+1 , i+1) || helper(s, dp , n, c-1 , i+1) || helper(s, dp , n, c, i+1);
    
}


    bool checkValidString(string s) {
        int n = s.size();
        vector<vector<int>> dp(n+1 , vector<int>(n+1, -1));

        return helper(s , dp , n, 0, 0);
        
    }
};