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
        unordered_set<string>visited;

        q.push(s);
        visited.insert(s);

        vector<string>ans;
        bool found = false;

    while (!q.empty() && !found) {
        int size = q.size();

        while (size--) {
            string x = q.front();
            q.pop();

            if (isValid(x)) {
                ans.push_back(x);
                found = true;
                continue;
            }

            // Don't generate next level once a valid level is found
            if (found)
                continue;

            for (int i = 0; i < x.size(); i++) {

                // Only remove parentheses
                if (x[i] != '(' && x[i] != ')')continue;

                string removed = x.substr(0, i) + x.substr(i + 1);
                cout<<removed<<' ';
                if (visited.find(removed) == visited.end()) {
                    visited.insert(removed);
                    q.push(removed);
                }
            }
        }
    }
        return ans;
    }
};