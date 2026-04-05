class Solution {
public:
    vector<int> partitionLabels(string s) {
        
        int n = s.size();

        // cal last index
        vector<int>index(26, -1);
        for(int i=0;i<n;i++) index[s[i]-'a'] = i;

        vector<int>res;
        int i =0;
        while(i<n){
            int l_idx = index[s[i]-'a'];

            for(int j = i+1 ; j<=l_idx ; j++){
                // if char occur after the last index then update the l_idx
                if( index[s[j]-'a'] > l_idx ) 
                    l_idx = index[s[j]-'a'];
            }

            res.push_back(l_idx-i+1);
            i = l_idx+1;
        }
        return res;
    }
};