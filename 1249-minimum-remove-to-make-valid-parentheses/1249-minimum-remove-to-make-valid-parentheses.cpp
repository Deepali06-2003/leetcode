class Solution {
public:
    string minRemoveToMakeValid(string s) {
        
        int n = s.size();
        stack<int>st;
        

        for(int i =0;i<n;i++){
            if(s[i] >='a' && s[i]<='z') continue;
            else{

                if(s[i] == '(') st.push(i);
                else{
                    if(!st.empty()) {
                        st.pop();
                    } else {
                        s[i] = '*';   // mark invalid ')'
                    }
                }
            }
        }
        
        while(!st.empty()){
            s[st.top()] = '*';
            st.pop();
        }

        s.erase(remove(s.begin(), s.end(), '*'), s.end());
        return s;

    }
};