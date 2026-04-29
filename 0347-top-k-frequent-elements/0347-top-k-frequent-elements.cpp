class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        int n = nums.size();
        
        unordered_map<int, int>mp;
        for(int i : nums)mp[i]++;

        vector<vector<int>>freq(n+1);
        for(auto j: mp){
            freq[j.second].push_back(j.first);
        }

        vector<int>res;
        for(int i =n;i>=0 ;i--){
            for(auto j : freq[i]){
                res.push_back(j);

                if(res.size() == k)return res;
            }
        }

        return res;
    }
};