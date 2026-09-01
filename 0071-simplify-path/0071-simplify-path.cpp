class Solution {
public:
    string simplifyPath(string path) {
        
        string s="";
        stringstream ss(path);

        stack<string>st;

        while(getline(ss, s, '/')){
            if(s=="." || s=="") continue;
            else if(s==".."){
                if(!st.empty()) st.pop();
            }
            else{
                st.push(s);
            }
        }

        string ans="";
        while(!st.empty()){
            string x = st.top();
            st.pop();

            if(ans.size()==0) ans = '/'+x;
            else ans = '/'+x+ans;
        }
        if(ans.size()==0) return "/";
        return ans;
    }
};