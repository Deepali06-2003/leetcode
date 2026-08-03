class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>>res;
        int dest = graph.size()-1;

        queue<vector<int>> q;
        q.push({0});

        while(!q.empty()){
            vector<int>temp = q.front();
            q.pop();

            int x = temp.back();
            if(x == dest){
                res.push_back(temp);
            }

            for(auto j: graph[x]){
                vector<int>curr = temp;
                curr.push_back(j);
                q.push(curr);
            }
        }

        return res;
    }
};