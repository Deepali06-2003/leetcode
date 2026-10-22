class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char>st;
        int l =0;
        int r=0, ans=0;

        while(r< s.size()){
            
            while(st.find(s[r]) != st.end() ){
                st.erase(s[l]);
                l++;
            }
            ans = max(ans , r-l+1);
            st.insert(s[r]);
            r++;
            
        }
        return ans;
    }
};
