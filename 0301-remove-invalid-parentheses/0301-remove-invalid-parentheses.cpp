class Solution {
public:

bool isValid(string s){
    int open = 0;
    for(char c:s){
        if(c == '(') open++;
        else if(c==')'){
            if(open > 0)open--;
            else return false;
        }
    }
    return open ==0;
}
    vector<string> removeInvalidParentheses(string s) {
        queue<string>q;
        unordered_set<string>st;

        q.push(s);
        st.insert(s);

        vector<string>ans;
        bool found = false;
        
        while(!q.empty()){
            
                string temp = q.front();
                q.pop();

                if(isValid(temp)){
                    found = true;

                    ans.push_back(temp);
                    while(!q.empty()){
                        string x = q.front();
                        q.pop();
                        if(isValid(x)){
                            ans.push_back(x);
                        }
                    }
                    break;
                }

                for(int idx = 0;idx<temp.size();idx++){
                    if(temp[idx]=='(' || temp[idx]==')'){
                        string remove = temp.substr(0, idx) + temp.substr(idx+1);

                        if(st.find(remove)==st.end()){
                            st.insert(remove);
                            q.push(remove);
                        }
                    }
                }

            
        }
        return ans;
    }
};