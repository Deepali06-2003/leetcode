class Solution {
public:
bool helper(vector<vector<int>>& adj, vector<int>& visited, int node){
    queue<int>q;

        q.push(node);
        visited[node]=0;

        while(!q.empty()){
            int x = q.front();
            q.pop();

            for(auto j : adj[x]){
                if(visited[j] == -1){
                    if(visited[x]==0)visited[j] = 1;
                    else visited[j] = 0;
                    q.push(j);
                }
                else if(visited[j]!= -1 && visited[j]==visited[x]) return false;
            }
        }
        return true;
}
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<vector<int>>adj(n+1);

        for(int i=0;i<dislikes.size();i++){
            adj[dislikes[i][0]].push_back(dislikes[i][1]);
            adj[dislikes[i][1]].push_back(dislikes[i][0]);
        }

        vector<int>visited(n+1, -1);

        for(int i=1;i<=n;i++){
            if(visited[i] == -1){
                if(!helper(adj , visited, i))return false;
            }
        }
        return true;
    }
};