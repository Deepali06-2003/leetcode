class Solution {
public:
bool helper(string& s , string& p, int i , int j , vector<vector<int>>& dp){

    if(p.size() == j){
        if(s.size()==i) return true;
        return false;
    }
    if(dp[i][j] != -1)return dp[i][j];

    bool first_char = false;
    if(i<s.length() && (p[j]==s[i] || p[j]=='.')) first_char = true;

    if(j+1 < p.size() && p[j+1] == '*'){
        bool n_take = helper( s , p , i , j+2 , dp);
        bool take = (first_char && helper(s , p , i+1 , j , dp));

        return dp[i][j] = n_take || take;
    }
    
        return  dp[i][j] = (first_char && helper(s , p, i+1 , j+1 , dp ) );
    
}
    bool isMatch(string s, string p) {
        vector<vector<int>> dp(s.length()+1, vector<int>(p.length()+1 , -1));
        return helper(s , p, 0 , 0, dp);
    }
};