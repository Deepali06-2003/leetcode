class Solution {
public:
    string minWindow(string s, string t) {
        
        int n = s.size() , m = t.size();
        if(m > n) return "";

        vector<int>freq(256, 0);
        for(char c : t) freq[c]++;

        int c=0, s_i = -1 , len = INT_MAX;
        int l=0, r=0;
        while(r<n){
            if(freq[s[r]]> 0)c++;
            freq[s[r]]--;
            r++;

            while(c==m){
                if((r-l) < len){
                    len = r-l;
                    s_i = l;
                }

                freq[s[l]]++;
                if(freq[s[l]] > 0)c--;
                l++;
            }
        }
        if(s_i == -1) return "";
        return s.substr(s_i , len);
    }
};