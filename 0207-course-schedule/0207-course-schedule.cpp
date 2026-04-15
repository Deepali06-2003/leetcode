class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int v = numCourses;
        vector<vector<int>> adj(v);
        for(int i=0;i<prerequisites.size();i++){
            int u = prerequisites[i][0];
            int v = prerequisites[i][1];
            adj[v].push_back(u);
        }

        vector<int>indegree(v, 0);
        for(int i=0;i<v;i++){
            for(auto j : adj[i])indegree[j]++;
        }

        queue<int>q;
        for(int i=0;i<v;i++){
            if(indegree[i]==0) q.push(i);
        }

        vector<int>res;
        while(!q.empty()){
            int x = q.front();
            q.pop();

            res.push_back(x);

            for(auto j: adj[x]){
                indegree[j]--;
                if(indegree[j]==0) q.push(j);
            }
        }

        return (res.size() == v);
    }
};