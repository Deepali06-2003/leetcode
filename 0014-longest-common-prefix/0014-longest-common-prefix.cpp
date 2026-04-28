class Solution {
public:
string helper(string& ans , string& s){
    string res="";
    int l =0, r=0;
    while(l<ans.size() && r<s.size()){

        if(ans[l] == s[r]) res = res + ans[l];
        else return res;
        l++;
        r++;
    }
    return res;
}
    string longestCommonPrefix(vector<string>& strs) {
        
        string ans = strs[0];
        for(int i =1;i<strs.size();i++){
            ans = helper(ans , strs[i]);

            if(ans == "")return ans;
        }
        return ans;
    }
};