class Solution {
public:
bool isPalindrome(string& s, int l, int h){
    while(l<h){
        if(s[l]!=s[h])return false;
        l++;
        h--;
    }
    return true;
}
void helper(string s, vector<vector<string>>& res,vector<string>& curr , int n ,int start){
    if(start == n){
        res.push_back(curr);
        return;
    }

    for(int i =start ;i<n ;i++){

        if(isPalindrome(s, start , i)){
            curr.push_back( s.substr(start , i-start+1) );
            helper(s, res, curr, n, i+1);
            curr.pop_back();
        }
    }
}
    vector<vector<string>> partition(string s) {
        
        vector<vector<string>>res;
        vector<string>curr;

        int n = s.size();
        helper(s, res, curr, n, 0);
        return res;
    }
};