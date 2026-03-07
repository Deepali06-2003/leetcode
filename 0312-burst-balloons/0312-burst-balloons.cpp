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

        vector<vector<int>>dp(n+1 , vector<int>(n+1 , -1));
        return helper(nums, 1 , n , dp);
        }
};