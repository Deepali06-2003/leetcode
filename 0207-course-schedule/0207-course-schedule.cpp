class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>adj(numCourses);
        for(int i =0;i<prerequisites.size();i++)
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);

        vector<int>indegree(numCourses , 0);
        for(int i =0;i<adj.size();i++){
            for(auto j: adj[i]) indegree[j]++;
        }

        queue<int>q;
        vector<int>res;

        for(int i =0;i<indegree.size();i++){
            if(indegree[i]==0)q.push(i);
        }

        while(!q.empty()){
            int x = q.front();
            q.pop();

            res.push_back(x);

            for(auto i:adj[x]){
                indegree[i]--;
                if(indegree[i]==0)q.push(i);
            }
        }

        return res.size()==numCourses;
    }
};