class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        
        queue<pair<string, int>>q;
        unordered_set<string >st(wordList.begin(), wordList.end());

        q.push({beginWord , 1});
        st.erase(beginWord);      // make it visited

        while(!q.empty()){

            string x = q.front().first;   // give the string 
            int step = q.front().second;  // no of step
            q.pop();

            if(x == endWord)return step;

            for(int i = 0; i < x.size(); i++) {
                char original = x[i];             
                 // now we will change character by character from a to z of each character of the string and
                 // check if it is present in set

                for(char j = 'a'; j <= 'z'; j++) {
                    x[i] = j;

                    if(st.find(x) != st.end()) {     //if found in set then make it vivited and push in q;
                        st.erase(x);
                        q.push({x, step + 1});
                    }
                }

                x[i] = original;                    // cahnge it to original word
            }
        }

        return 0;

    }
};