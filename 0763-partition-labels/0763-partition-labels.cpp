class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int>res;
        
        int n = s.size();
        unordered_map<char, int>mp;
        for(int i=0;i<n;i++)mp[s[i]] = i;

        int i=0;
        while(i<n){
            int l_idx = mp[s[i]];

            for(int j=i+1;j<=l_idx;j++){
                l_idx = max( l_idx , mp[s[j]] );
            }

            res.push_back(l_idx-i+1);
            i = l_idx+1;
        }
        return res;
    }
};