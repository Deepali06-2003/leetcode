class Solution {
public:
int m,n;
int ans=0;
    long long solve(int i,int j,string s,string t,vector<vector<long long>>&dp){
          if(j==t.size()) return 1;
          if(i>=s.size() || j>t.size()) return 0;
          if (s.size() - i < t.size() - j) return 0;
          if(dp[i][j]!=-1) return dp[i][j];
          long long ans=0;
          if(s[i]==t[j]) ans+=solve(i+1,j+1,s,t,dp);
          ans+=solve(i+1,j,s,t,dp);
          return dp[i][j]=ans;
    }
    int numDistinct(string s, string t) {
        m=s.size();
        n=t.size();
        vector<vector<long long>>dp(m+1,vector<long long>(n+1,-1));
        return solve(0,0,s,t,dp);
    }
};