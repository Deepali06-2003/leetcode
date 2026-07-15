class Solution {
public:
    string reverseWords(string s) {
        
        string ans="";
        string token="";
        int n = s.size();

        stringstream ss(s);

        while(getline(ss, token, ' ')){
            if(token == "") continue;
            if(ans.empty()) ans = token;
            else ans = token + " "+ ans;
        }

        return ans;
    }
};