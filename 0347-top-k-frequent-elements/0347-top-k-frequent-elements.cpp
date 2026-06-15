class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        int n = nums.size();
        unordered_map<int, int> f;
        for(int i:nums) f[i]++;

        vector<vector<int>> freq(n+1);
        for(auto j: f){
            freq[j.second].push_back(j.first);
        }

        vector<int>res;
        for(int i = freq.size()-1 ; i>=0;i--){
            for(auto j:freq[i]){
                res.push_back(j);

                if(res.size() == k) return res;
            }
        }return res;
    }
};

 