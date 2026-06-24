class Solution {
public:


    vector<int> largestDivisibleSubset(vector<int>& nums) {
        
        int n = nums.size();
        sort(nums.begin(),nums.end());

        vector<int>dp(n , 1);
        vector<int>prev_idx(n, -1);
        int max_len = 1, last_idx=0;

        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[i]%nums[j] == 0){
                    // updating dp[i] if it is smaller
                    if(dp[i] < (dp[j]+1) ){
                        dp[i] = dp[j]+1;
                        prev_idx[i] = j;
                    }
                    // updating max_length and last index having longest substring
                    if(max_len < dp[i]){
                        last_idx = i;
                        max_len = max(max_len , dp[i]);
                    }
                }
                                
            }
        }

        vector<int>ans;
        while(last_idx != -1){
            ans.push_back(nums[last_idx]);
            last_idx = prev_idx[last_idx];
        }
        return ans;
    }
};