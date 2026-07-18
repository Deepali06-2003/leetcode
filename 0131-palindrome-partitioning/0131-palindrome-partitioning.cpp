class Solution {
public:
bool Palindrome(string& s, int l , int h){
    while(l<h){
        if(s[l] != s[h]) return false;
        l++; h--;
    }
    return true;
}


void helper(string s, vector<vector<string>>& res, vector<string>& curr, int idx, int n ){
    if( idx == n){
        res.push_back(curr); 
        return;}
    
    for(int i = idx ; i<n;i++){
        if(Palindrome(s , idx , i)){
            curr.push_back(s.substr(idx, i-idx+1));
            helper(s, res, curr, i+1, n);
            curr.pop_back();
        }
    }
}
    vector<vector<string>> partition(string s) {
        int n = s.size();

        vector<vector<string>>res;
        vector<string>curr;

        helper(s, res, curr, 0, n);
        return res;
    }
};