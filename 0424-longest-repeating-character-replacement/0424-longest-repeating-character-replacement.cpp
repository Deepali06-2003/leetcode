class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        int max_len = -1, max_c=0 ;

        int l =0;
        int r=0;

        vector<int>freq(26, 0);

        while(r<n){
            freq[s[r]-'A']++;
            max_c = max(max_c , freq[s[r]-'A']);

            if((r-l+1)-max_c > k){
                freq[s[l]-'A']--;
                l++;
            }
            if((r-l+1)-max_c <= k){
                max_len = max( max_len , (r-l+1));
            }

            r++;
        }
        return max_len;
    }
};

