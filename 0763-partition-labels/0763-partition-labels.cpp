class Solution {
public:
    vector<int> partitionLabels(string s) {
        
        int n = s.size();
        vector<int>res;

        vector<int>mp(26, -1);
        for(int i=0;i<n;i++)mp[s[i]-'a'] =i;

        int i=0;
        while(i<n){

            int l_idx = mp[s[i]-'a'];

            for(int j=i+1;j<=l_idx;j++){
                if(mp[s[j]-'a'] > l_idx) l_idx = mp[s[j]-'a'];
            }

            res.push_back(l_idx-i+1);
            i = 1+l_idx;
        }
        return res;
    }
};

