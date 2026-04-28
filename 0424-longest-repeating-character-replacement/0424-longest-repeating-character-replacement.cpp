class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        int l =0 , r=0;

        vector<int>freq(26, 0);

        int max_l=0, max_freq=0;

        while(r<n){
            freq[s[r]-'A']++;
            max_freq = max(max_freq, freq[s[r]-'A']);

            if((r-l+1)-max_freq > k){
                freq[s[l]-'A']--;
                l++;
            }
            if((r-l+1)-max_freq <= k){
                max_l = max(max_l, r-l+1);
            }

            r++;
        }

        return max_l;

    }
};