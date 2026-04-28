class Solution {
public:

void helper(string& s, int l , int h , int& ans){
    while(l>=0 && h<s.size() && s[l]==s[h]){
        l--;
        h++;
        ans++;
    }
}
    int countSubstrings(string s) {
        int ans=0;
        for(int i =0;i<s.size();i++){
           helper(s, i , i, ans);
            helper(s, i, i+1, ans);
        }

        return ans;
    }
};