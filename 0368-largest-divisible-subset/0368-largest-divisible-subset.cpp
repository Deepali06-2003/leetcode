class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return nums;

        sort(nums.begin() , nums.end());

        int last_idx = 0, ans = 0;

        vector<int>dp(n,1);
        vector<int>prev(n, -1);

        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){

                if(nums[i]%nums[j]==0){

                    if(dp[j]+1 > dp[i]){
                        dp[i]=dp[j]+1;
                        prev[i] = j;
                    }
                    if(dp[i]>ans){
                        ans = dp[i];
                        last_idx = i;
                    }
                }
            }
        }

        vector<int>res;
        while(last_idx != -1){
            res.push_back(nums[last_idx]);
            last_idx = prev[last_idx];
        }
        return res;
    }
};