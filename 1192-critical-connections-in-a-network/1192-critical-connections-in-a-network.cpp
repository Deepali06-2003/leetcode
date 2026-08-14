class Solution {
public:
int timer=1;
vector<vector<int>>res;

void dfs(vector<vector<int>>& adj, vector<int>& visited, vector<int>& t_insert, vector<int>& lowest , int n, int parent){

    visited[n]=1;
    lowest[n] = t_insert[n]=timer;
    timer++;

    for(auto j: adj[n]){
        if(j == parent) continue;
        else if(visited[j]==0){
            dfs(adj, visited, t_insert, lowest, j, n);
            lowest[n] = min(lowest[j], lowest[n]);

            if(t_insert[n] < lowest[j]){
                //bridge found
                res.push_back({n, j});
            }
        }
        else{   // visited[j]==1
            lowest[n] = min(lowest[j], lowest[n]);
        }
    }
}
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>>adj(n);
        for(int i=0;i<connections.size();i++){
            adj[connections[i][0]].push_back(connections[i][1]);
            adj[connections[i][1]].push_back(connections[i][0]);
        }

        vector<int>visited(n, 0);
        vector<int>t_insert(n);
        vector<int>lowest(n);

        dfs(adj, visited, t_insert, lowest, 0, -1);
        return res;
    }
};