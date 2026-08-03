class Solution {
public:

void helper(string& s, unordered_set<string>& st, vector<string>& res, string curr , int n, int idx){
    if(idx == n){
        res.push_back(curr);
        return;
    }

    for(int len=1; len+idx<=n ; len++){
        string temp = s.substr(idx , len);

        if(st.find(temp) != st.end()){
            string next;
            if(curr.empty()) next = temp;
            else next = curr+ " "+ temp;

            helper(s, st, res, next, n, idx+len);
        }
    }
}
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        vector<string>res;
        string curr;

        int n = s.size();
        unordered_set<string>st;
        for(string w : wordDict) st.insert(w);

        helper(s, st , res, curr , n , 0 );
        return res;
    }
};