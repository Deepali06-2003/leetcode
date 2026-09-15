class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int ans = nums[0] , min_e = nums[0], max_e = nums[0];

        for(int i=1;i<nums.size();i++){
            int a = min_e * nums[i];
            int b = max_e * nums[i];

            min_e = min({b , a, nums[i]});
            max_e = max({a , b, nums[i]});

            ans = max({max_e , ans});
        }

        return ans;
    }
};

