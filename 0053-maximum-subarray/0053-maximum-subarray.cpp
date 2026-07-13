class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        
        int n = nums.size();

        int ans = INT_MIN, cur = 0;

        for(int i : nums){
            cur = cur + i;
            ans = max(ans , cur);
            if(cur<0) cur = 0;
        }

        return ans;
    }
};