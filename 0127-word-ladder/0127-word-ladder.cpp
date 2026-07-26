class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        
        unordered_set<string>s;
        for(string w : wordList) s.insert(w);

        queue<pair<string, int>>q;
        q.push({beginWord, 1});

        while(!q.empty()){
            string temp = q.front().first;
            int step = q.front().second;
            q.pop();

            if(temp == endWord) return step;
            for(int i=0;i<temp.size();i++){

                char x = temp[i];
                for(char c='a'; c<='z'; c++){
                    temp[i]=c;

                    if(s.find(temp) != s.end()){
                        q.push({temp, step+1});
                        s.erase(temp);
                    }
                }
                temp[i] = x;
            }
        }
        return 0;
    }
};