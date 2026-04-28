class Solution {
public:
    string minWindow(string s, string t) {
        
        vector<int>freq(256, 0);
        int n = s.size() , m = t.size();
        if(m> n)return "";

        for(int i =0;i<m;i++) freq[t[i]]++;

        int l =0 , r=0;
        int s_i =-1, min_len = INT_MAX;
        int c=0;

        while(r<n){
            
            if(freq[s[r]]>0)c++;
            freq[s[r]]--;
            r++;

            while(c==m){
                if((r-l)<min_len){
                    min_len = r-l;
                    s_i = l;
                }
                freq[s[l]]++;
                if(freq[s[l]]> 0) c--;
                l++;
            }
        }

        if(s_i==-1)return "";
        return s.substr(s_i, min_len);
              

    }
};