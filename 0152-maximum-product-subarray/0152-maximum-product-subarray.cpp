class Solution {
public:
    int maxProduct(vector<int>& nums) {
       
    int n = nums.size();

    int curMax = nums[0];
    int curMin = nums[0];
    int ans = nums[0];

    for (int i = 1; i < n; i++) {

       int a = curMax * nums[i];
       int b = curMin *nums[i];

        curMax = max({nums[i] , a , b});
        curMin = min({nums[i]  , a , b});

        ans = max(ans , curMax);


    }
    return ans;

    }
};