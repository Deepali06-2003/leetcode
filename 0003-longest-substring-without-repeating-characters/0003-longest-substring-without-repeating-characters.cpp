class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        int n = s.size();
        unordered_set<char>st;
        int ans=0;

        int l=0, r=0;
        while(r<n){
            while(st.find(s[r]) != st.end()){
                st.erase(s[l]);
                l++;
            }
            ans = max(ans, r-l+1);
            st.insert(s[r]);
            r++;
        }
        return ans;
    }
};