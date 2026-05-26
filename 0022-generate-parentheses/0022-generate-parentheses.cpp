class Solution {
public:

void helper(vector<string>& res , string& curr , int n , int open , int close){
    if( n == close){
        res.push_back(curr);
        return;
    }

    if(open<n){
        curr = curr + '(';
        helper(res, curr , n , open+1, close);
        curr.pop_back();
    }
    if(close<open){
        curr = curr + ')';
        helper(res, curr , n , open, close+1);
        curr.pop_back();
    }
}
    vector<string> generateParenthesis(int n) {
        vector<string>res;
        string curr;

        helper(res , curr , n , 0 , 0);
        return res;
    }
};