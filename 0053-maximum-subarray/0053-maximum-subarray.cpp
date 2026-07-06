class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        
        int n = nums.size();

        int ans = INT_MIN, s=0;

        for(int i: nums){
            s = s+i;
            ans = max(ans , s);
            if(s < 0) s=0;
        }
        return ans;
    }
};