class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int c=0;
        unordered_map<int, int>mp;

        for(int i=0;i<nums.size();i++){
            if(mp.find(nums[i]) != mp.end()){
                c = c+ mp[nums[i]];
            }
            mp[nums[i]]++;
        }
        return c;
    }
};