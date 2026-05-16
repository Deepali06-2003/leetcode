class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        
        unordered_set<string>st;
        for(string s : wordList) st.insert(s);

        queue<pair<string, int>>q;
        q.push({beginWord, 1});
        st.erase(beginWord);

        while(!q.empty()){

            string word = q.front().first;
            int step = q.front().second;
            q.pop();

            if(word == endWord) return step;
            
            for(int i = 0; i<word.size() ;i++){

                char original = word[i];
                for(char c ='a' ; c<='z'; c++){
                    word[i] = c;

                    if(st.find(word) != st.end()){

                        st.erase(word);
                        q.push({word, step+1});
                    }
                }

                word[i] = original;
            }
        }

        return 0;
    }
};