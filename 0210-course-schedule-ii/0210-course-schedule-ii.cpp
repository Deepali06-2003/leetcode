class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
         vector<int>res;

        vector<vector<int>>adj(numCourses);
        for(int i=0;i<prerequisites.size();i++) adj[prerequisites[i][1]].push_back(prerequisites[i][0]);

        vector<int>indegree(numCourses, 0);
        queue<int>q;

        for(int i=0;i<numCourses;i++){
            for(auto j : adj[i]) indegree[j]++;
        }

        for(int i=0;i<numCourses;i++){
            if(indegree[i]==0) q.push(i);
        }

        while(!q.empty()){
            int x = q.front();
            q.pop();

            res.push_back(x);

            for(auto j: adj[x]){
                indegree[j]--;
                if(indegree[j]==0) q.push(j);
            }
        }

        if (res.size() == numCourses) return res;
        return{};
    }
};