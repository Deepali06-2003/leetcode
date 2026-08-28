class Solution {
public:
    string reverseWords(string s) {
        string ans="";
        string t="";
        stringstream ss(s);

        while(getline(ss, t, ' ')){
            if(t == "") continue;
            if(ans.empty()) ans = t;
            else ans = t + " "+ans;
        }
        return ans;
    }
};


