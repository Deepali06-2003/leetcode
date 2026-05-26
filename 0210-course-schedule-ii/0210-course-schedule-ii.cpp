class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        
        vector<int>res;

        vector<vector<int>> adj(numCourses);
        for(int i =0;i< prerequisites.size(); i++){
            int u = prerequisites[i][0];
            int v = prerequisites[i][1];
            adj[v].push_back(u);
        }

        vector<int>indegree(numCourses, 0);
        for(int i =0;i< indegree.size();i++){
            for(auto j: adj[i]){
                indegree[j]++;
            }
        }

        queue<int>q;
        for(int i =0;i< indegree.size();i++){
            if(indegree[i] == 0) q.push(i);
        }

        while(!q.empty()){
            int i = q.front();
            q.pop();

            res.push_back(i);

            for(auto j : adj[i]){
                indegree[j]--;
                if(indegree[j]==0) q.push(j);
            }
        }

        if(res.size() == numCourses) return res;
        return {};
    }
};