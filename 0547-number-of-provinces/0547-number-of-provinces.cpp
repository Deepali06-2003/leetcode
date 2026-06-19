class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();

        vector<vector<int>>adj(n);
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(isConnected[i][j] == 1){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }

        vector<bool>visited(n, false);
        int ans =0;
        stack<int>st;

        for(int i=0;i<n;i++){
            if(!visited[i]){
                ans++;

                visited[i] = true;
                st.push(i);

                while(!st.empty()){
                    int t = st.top();
                    st.pop();

                    for(int j : adj[t]){
                        if(!visited[j]){
                            visited[j] = true;
                            st.push(j);
                        }
                    }

                }


            }
        }  
        return ans; 
    }
};
