class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        
        stack<string>st;

        for(string s : tokens){
            if(s=="+" || s=="-" || s=="*" || s=="/"){
                string x = st.top();
                st.pop();
                string y = st.top();
                st.pop();

                //int a = int(y) int(x);

                if(s=="+"){
                   int a = stoi(y) + stoi(x);
                   st.push(to_string(a));
                }
                else if(s=="-"){
                     int a = stoi(y) - stoi(x);
                   st.push(to_string(a));
                }
                else if(s == "*"){
                    int a = stoi(y) * stoi(x);
                   st.push(to_string(a));
                }
                else{
                    int a = stoi(y) / stoi(x);
                   st.push(to_string(a));
                }
            }

            else{
                st.push(s);
            }
        }

        return stoi(st.top());
    }
};