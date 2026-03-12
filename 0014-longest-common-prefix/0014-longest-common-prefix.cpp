class Solution {
public:
string helper(string x1 , string x2){

    string ans = "";
    int i =0, j=0;

    while(i<x1.size() && j<x2.size() ){
        if(x1[i] == x2[j]){
            ans = ans+x1[i];
            i++; j++;
        }
        else return ans;
    }
    return ans;
}
    string longestCommonPrefix(vector<string>& strs) {
        
        string ans = strs[0];
        for(int i =1 ;i<strs.size() ;i++){
            ans = helper(ans , strs[i]);
        }
        return ans;
    }
};