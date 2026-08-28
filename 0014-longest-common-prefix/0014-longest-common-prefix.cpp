class Solution {
public:

string helper(string x, string y){
    string ans="";
    int i=0, j=0;
    while(i<x.size() && j<y.size() && x[i]==y[j]){
        ans = ans + x[i];
        i++; j++;
    }
    return ans;
}
    string longestCommonPrefix(vector<string>& strs) {
        string ans = strs[0];
        for(int i=1;i<strs.size(); i++){
            ans = helper(ans, strs[i]);

            if(ans == "") return "";
        }
        return ans;
    }
};