class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();

        if(s.size()==0 || s[0]=='0') return 0;

        vector<int>dp(n+1 , 0);
        dp[1] = 1;
        dp[0]=1;
        for(int i=2;i<=n ;i++){

            if(s[i-1]!='0') dp[i]= dp[i]+dp[i-1];

            int x = (s[i-2]-'0')*10 + (s[i-1]-'0');
            if(x>=10 && x<=26) dp[i] = dp[i]+dp[i-2];
        }
        return dp[n];
    }
};