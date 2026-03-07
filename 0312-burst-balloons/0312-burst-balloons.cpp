class Solution {
public:
int helper(vector<int>& nums , int l , int r, vector<vector<int>>& dp){

    if(l>r) return 0;
    if(dp[l][r] != -1)return dp[l][r];

    int m = INT_MIN;

    for(int i = l ; i<=r ;i++){
        int x = nums[i]* nums[l-1]*nums[r+1];

        x = x+ helper(nums , l , i-1, dp) + helper(nums , i+1 , r, dp);
        m = max(m , x);
    }
    return dp[l][r] = m;
   
}
    int maxCoins(vector<int>& nums) {
        int n = nums.size();

        if(n==0)return 0;
        if(n==1)return nums[0];
        
        
        nums.insert(nums.begin(), 1);
        nums.push_back(1);

        vector<vector<int>>dp(n+2 , vector<int>(n+2 , 0));

        for(int i =n;i>=1 ;i--){
            for(int j =1;j<=n;j++){
                if(i>j)continue;

                int m = INT_MIN;

                for(int ind = i ; ind<=j ;ind++){
                    int x = nums[ind]* nums[i-1]*nums[j+1];

                    x = x+ dp[i][ind-1] + dp[ind+1][j];
                    m = max(m , x);
                }
                dp[i][j]= m;
            }
        }
        return dp[1][n];
        
        }
};