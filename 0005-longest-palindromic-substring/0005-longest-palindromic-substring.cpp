class Solution {
public:

string helper(string& s, int l, int h){

    while(l>=0 && h<s.size() && s[l]==s[h]){
        l--;
        h++;
    }
    return s.substr(l+1, h-l-1);
}
    string longestPalindrome(string s) {
        string ans="";

        for(int i=0;i<s.size();i++){
            string odd = helper(s, i, i);
            string even = helper(s, i, i+1);

            if(odd.size()>ans.size()) ans = odd;
            if(even.size()>ans.size()) ans = even;
        }
        return ans;
    }
};