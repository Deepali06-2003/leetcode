class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        
        unordered_map<int, int>mp; //int , sum
        int sum =0;
        mp[sum]=1;
        int ans=0;


        for(int i =0;i<nums.size();i++){
            sum = sum+nums[i];
            if(mp.find(sum-k)!=mp.end()) ans = ans+mp[sum-k];
            mp[sum]++;

        }
        return ans;
    }
};