class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        
        unordered_set<string>st;
        for(string s: wordList) st.insert(s);

        st.erase(beginWord);
        queue<pair<string, int>>q;

        q.push({beginWord, 1});

        while(!q.empty()){
            auto t = q.front();
            q.pop();

            string x = t.first;
            int ans = t.second;

            if(x == endWord) return ans;
            for(int i=0;i<x.size();i++){
                char c = x[i];
                
                for(char y ='a'; y<='z';y++){
                    x[i]=y;
                    if(st.find(x) != st.end()){
                        st.erase(x);
                        q.push({x, ans+1});
                    }
                }
                x[i]=c;
            }
        }

        return 0;
    }
};