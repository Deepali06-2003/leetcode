class Solution {
public:
    string answerString(string word, int numFriends) {
        
        int n = word.size();
        if(numFriends == 1) return word;

        int max_len_possible = n-(numFriends-1);

       string ans = "";
        for(int i=0; i<n; i++){
            int possible_l = min(max_len_possible, n-i);
            string temp = word.substr(i , possible_l);

            if(temp > ans) ans = temp;
        }
        return ans;
}
};