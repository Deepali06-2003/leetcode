class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        
        int n = s1.size(), m = s2.size();
        
        if(n> m)return false;

        vector<int>freq1(26, 0);
        vector<int>freq(26, 0);

        for(char c: s1)freq1[c-'a']++;

        int l=0;
        for(int r =0;r<m;r++){
            freq[s2[r]-'a']++;

            if((r-l+1) > n){
                freq[s2[l]-'a']--;
                l++;
            }
            if((r-l+1)==n){
                if(freq == freq1) return true;
            }
        }
        return false;
    }
};