class Solution {
public:
    int climbStairs(int n) {
        
        if(n==0 || n==1) return 1;
        if(n==2) return 2;

 //       vector<int>dp(n+1, 0);
   //     dp[0]=1 , dp[1]=1;

 //dp[i]= dp[i-1]+dp[i-2];

        //return dp[n];


        int a = 1, b=1;
        int ans= 0;

        for(int i=2;i<=n;i++){
            ans = a + b;
            a=b;
            b = ans;
        }
        return ans;
    }
};