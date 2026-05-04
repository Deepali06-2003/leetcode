class Solution {
public:
    int maxProduct(vector<int>& nums) {
        
        int n = nums.size();

        int ans = nums[0] , max_e = nums[0] , min_e = nums[0];
        for(int i =1;i<n ;i++){
            int a = max_e * nums[i];
            int b = min_e * nums[i];

            min_e = min({a, b, nums[i]});
            max_e = max({a, b, nums[i]});

            ans = max(ans , max_e);
        }

        return ans;
    }
};