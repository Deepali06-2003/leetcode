class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        
        unordered_set<string>st;
        for(string s : wordList)st.insert(s);

        queue<pair<string, int>>q;
        q.push({beginWord, 1});

        while(!q.empty()){
            string word = q.front().first;
            int step = q.front().second;
            q.pop();

            if(word == endWord) return step;

            for(int j=0;j<word.size(); j++){
                char x = word[j];
                for(char k='a'; k<='z';k++){
                    word[j]=k;

                    if(st.find(word) != st.end()){
                        q.push({word, step+1});
                    }
                    st.erase(word);
                }
                word[j] = x;
            }
        }
        return 0;

    }
};