class Solution {
public:

bool helper(string s, int count, int i , vector<vector<int>>& dp){
    if(i == s.size()) return (count==0);
    if(count<0) return false;

    if(dp[i][count]!=-1) return dp[i][count];

    if(s[i]=='('){
        return dp[i][count] =helper(s, count+1, i+1, dp);
    }
    else if(s[i]==')') return dp[i][count] =helper(s, count-1, i+1, dp);
    else
        return dp[i][count] = helper(s, count+1, i+1, dp) || helper(s, count-1, i+1, dp) || helper(s, count, i+1, dp);
}

    bool checkValidString(string s) {
        int n = s.size();
        vector<vector<int>> dp(n+1 , vector<int>(n+1, -1));
       return helper(s, 0,0, dp);
    }
};