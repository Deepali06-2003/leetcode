class Solution {
public:
bool helper(vector<vector<int>>& graph,  vector<int>& visited , int node){

    queue<int>q;

        q.push(node);
        visited[node]=0;

        while(!q.empty()){
            int n = q.front();
            q.pop();

            for(auto j: graph[n]){
                if(visited[j] == -1){
                    if(visited[n]==0) visited[j] = 1;
                    else visited[j] = 0;

                    q.push(j);
                }

                else if(visited[j] != -1 && visited[j] == visited[n]) return false;
            }
        }
    return true;
}

    bool isBipartite(vector<vector<int>>& graph) {
        int V = graph.size();
        vector<int>visited(V, -1);
        
        for(int i=0;i<V;i++){
            if(visited[i] == -1){
                if(!helper(graph , visited, i)) return false;
            }
        }

        return true;
    }
};