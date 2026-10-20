class Solution {
public:
    int maxProduct(vector<int>& nums) {
        
        int n = nums.size();

        int ans = nums[0] , a=nums[0], b=nums[0];

        for(int i=1;i<n;i++){
            
            int x = a*nums[i];
            int y = b*nums[i];
            
            a = min({x, y, nums[i]});
            b = max({x, y, nums[i]});

            ans = max({b , nums[i] , ans});
        }

        return ans;
    }
};