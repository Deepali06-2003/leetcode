class Solution {
public:
string helper(string& x, string& y){

    int a = 0, b=0;
    string ans="";

    while(a<x.size() && b<y.size()){
        if(x[a] == y[b]) ans = ans + x[a];
        else return ans;
        a++;
        b++;
    }
    return ans;
}

    string longestCommonPrefix(vector<string>& strs) {
        
        string ans = strs[0];
        for(int i=1;i<strs.size() ;i++){

            ans = helper(strs[i] , ans);
        }
        return ans;
    }
};