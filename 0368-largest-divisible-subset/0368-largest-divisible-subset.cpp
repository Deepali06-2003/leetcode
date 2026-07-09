class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        
        sort(nums.begin(), nums.end());

        int n = nums.size();
        vector<int>prev(n, -1);
        vector<int>dp(n , 1);
        int max_len = 1, last_idx =0;

        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[i] % nums[j] == 0){

                    if(dp[j]+1 > dp[i]){
                        dp[i]= dp[j]+1;
                        prev[i] = j;
                    }

                    if(dp[i] > max_len){
                        max_len = dp[i];
                        last_idx = i;
                    }
                }
            }
        }
        vector<int>res;
        while(last_idx != -1){
            res.push_back(nums[last_idx]);
            last_idx = prev[last_idx];
        }return res;
    }
};