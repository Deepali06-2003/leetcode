class Solution {
public:

bool helper(vector<vector<int>>& graph , vector<int>& visited, int node, int p){
   queue<int>q;

   q.push(node);
   visited[node]=0;

   while(!q.empty()){
    int x = q.front();
    q.pop();

    for(auto j: graph[x]){
        if(visited[j]==-1){
            if(visited[x]==0) visited[j]=1;
            else visited[j]=0;

            q.push(j);
        }
        else if( (visited[j]!=-1) && (visited[j]==visited[x]) ) return true;
    }
   }
    return false;
}
    bool isBipartite(vector<vector<int>>& graph) {
        
        int n = graph.size();
        vector<int>visited(n, -1);

        for(int i=0;i<n;i++){
            if(visited[i]==-1){
                if(helper(graph, visited , i, -1)==true) return false;
            }
        }

        return true;
    }
};