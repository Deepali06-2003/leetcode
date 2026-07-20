class Solution {
public:
void dfs(int node, vector<vector<int>>& isConnected, vector<int>& visited ){
    visited[node] =1;

    for(int j=0 ;j< isConnected.size() ; j++){
        if(isConnected[node][j]==1 && visited[j] == 0) dfs(j, isConnected, visited);
    }
}
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();

        int ans=0;
        vector<int>visited(n, 0);

        for(int i=0;i<n;i++){
            if(visited[i] == 0){
                dfs(i, isConnected , visited);
                ans++;
            }
        }

        return ans;
    }
};