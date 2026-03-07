class Solution {
public:

int ans=0;
    long long solve(int i,int j,string s,string t,int n , int m , vector<vector<long long>>&dp){
          
          if(j==m) return 1;
          if(i>=n || j>m) return 0;
          //if (s.size() - i < t.size() - j) return 0;

          if(dp[i][j]!=-1) return dp[i][j];

          long long ans=0;
          if(s[i]==t[j]){
            ans = ans+ solve(i+1 , j+1 , s, t , n , m , dp)+solve(i+1, j , s , t, n , m , dp);
          }
          else{
            ans = ans+solve(i+1, j , s , t, n , m , dp);
          }
          return dp[i][j]=ans;
    }
    int numDistinct(string s, string t) {
        int n=s.size();
        int m=t.size();
        vector<vector<long long>>dp(n+1,vector<long long>(m+1,-1));
        return solve(0,0,s,t,n, m , dp);
    }
};