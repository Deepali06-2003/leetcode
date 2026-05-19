class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>>res;

        int n = nums.size();

        sort(nums.begin(), nums.end());

        for(int i=0;i<n-1;i++){
            int s = -nums[i];

            if(i>0 && nums[i]==nums[i-1]) continue;

            int j = i+1, k=n-1;
            while(j<k){
                if((nums[j]+nums[k]) == s){
                    vector<int>curr = {nums[i], nums[j], nums[k]};
                    res.push_back(curr);
                    j++;
                    k--;

                    while(j<k && nums[j]== nums[j-1]) j++;
                    while(j<k && nums[k]== nums[k+1]) k--;
                }
                else if((nums[j]+nums[k]) > s) k--;
                else j++;
            }
        }

        return res;
    }
};