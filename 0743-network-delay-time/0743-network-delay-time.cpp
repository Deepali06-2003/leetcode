class Solution {
public:


    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        
       unordered_map<int , vector<pair<int, int>>>adj;
        for(int i=0;i< times.size();i++){
            int u = times[i][0];
            int v = times[i][1];
            int t = times[i][2];

            adj[u].push_back({v, t});
        }

        priority_queue<pair<int, int>, vector<pair<int, int>> , greater<pair<int , int>>> pq;

        vector<int>res(n+1, INT_MAX);
        res[k] = 0;
        pq.push({0, k});

        while(!pq.empty()){

            int d = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            for(auto& vec: adj[node]){
                int adjN = vec.first;
                int dis = vec.second;

                if(d + dis < res[adjN]){
                    res[adjN] = d+dis;
                    pq.push({d+dis , adjN});
                }
            }
        }

        int ans = INT_MIN;
        for(int i =1;i<= n ;i++) ans = max(ans , res[i]);

        return ans == INT_MAX ? -1 : ans;
    }
};