class Solution {
public:

bool helper(string s, unordered_set<string>& st,vector<int>& dp, int i ){
    if(i == s.size()) return true;

    if(dp[i] != -1) return dp[i];

    for(int l =1;l<=s.size()-i;l++){
        string x = s.substr(i, l);

        if( (st.find(x) != st.end()) && helper(s, st, dp, i+l) ) return dp[i]=1;
    }
    return dp[i]=0;
}

    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string>st;
        for(string a:wordDict) st.insert(a);

        int n = s.size();

        vector<int>dp(n, -1);
        return helper(s, st , dp , 0);
    }
};