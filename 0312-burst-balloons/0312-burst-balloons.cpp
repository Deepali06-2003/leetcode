class Solution {
public:
int helper(vector<int>& nums, vector<vector<int>>& dp, int l , int h ){
    if(l>h)return 0;
    if(dp[l][h]!=-1)return dp[l][h];

    int ans = INT_MIN;
    for(int i =l;i<=h;i++){
        int x = nums[l-1]*nums[h+1]*nums[i];
        x= x+ helper(nums, dp , l, i-1) + helper(nums, dp,i+1, h);

        ans = max(ans, x);
    }
    return dp[l][h] = ans;
}
    int maxCoins(vector<int>& nums) {
        
        int n = nums.size();
        vector<vector<int>>dp(n+1, vector<int>(n+1 , -1));

        nums.push_back(1);
        nums.insert(nums.begin(), 1);
        return helper(nums , dp , 1, n);
    }
};