class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>>res;

        int n = nums.size();

        sort(nums.begin(), nums.end());

        for(int i=0;i<n-1;i++){
            if(i>0 && nums[i]==nums[i-1]) continue;

            int s = -nums[i];

            int l = i+1, h= n-1;
            while(l<h){
                if((nums[l]+nums[h]) == s){
                    res.push_back({nums[i], nums[l], nums[h]});
                    l++;
                    h--;

                    while(l<h && nums[l-1]==nums[l]) l++;
                    while(l<h && nums[h+1]==nums[h]) h--;
                }
                else if((nums[l]+nums[h]) > s) h--;
                else l++;
            }
        }

        return res;
    }
};