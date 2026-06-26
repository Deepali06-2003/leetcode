class Solution {
public:
    int maxProduct(vector<int>& nums) {
        
        int ans = nums[0] , MIN = nums[0] , MAX = nums[0];

        for(int i=1;i<nums.size();i++){
            int a = MIN * nums[i];
            int b = MAX * nums[i];

            MIN = min({a, b , nums[i]});
            MAX = max({a, b, nums[i]});
            ans = max({MAX , ans, nums[i]});
        }
        return ans;
    }
};