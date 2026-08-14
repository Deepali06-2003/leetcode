class Solution {
public:

bool dfs(vector<vector<int>>&  adj, vector<int>& visited, int n, int destination){
    if(n == destination) return true;
    visited[n]=1;

    for(auto j: adj[n]){
        if(visited[j]==0){
            if(dfs(adj, visited, j, destination)==true) return true;
        }
    }
    return false;
}
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        
        vector<vector<int>>adj(n);
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }

        vector<int>viisted(n, 0);
        return dfs(adj, viisted, source, destination);
    }
};