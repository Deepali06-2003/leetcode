class Solution {
public:
    vector<int> partitionLabels(string s) {
        
        unordered_map<char, int>mp;
        for(int i=0;i<s.size();i++) mp[s[i]]=i;

        vector<int>res;
        
        int i =0;
        while(i<s.size()){
            int last_idx = mp[s[i]];
            for(int j=i+1;j<=last_idx;j++){
                if(mp[s[j]] > last_idx ) last_idx = mp[s[j]];
            }

            res.push_back(last_idx-i+1);
            i = last_idx+1;
        }
        return res;
    }
};