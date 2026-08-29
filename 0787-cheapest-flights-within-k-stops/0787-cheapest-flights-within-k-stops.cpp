class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        
        vector<vector<pair<int,int>>>adj(n);
        for(int i=0;i<flights.size() ;i++){
            int u = flights[i][0];
            int v = flights[i][1];
            int c = flights[i][2];

            adj[u].push_back({v, c});
        }
                // stops, node , dist
        queue<pair<int, pair<int, int>>>q;
        vector<int>dist(n, INT_MAX);

        q.push({0, {src, 0}});
        dist[src]=0;

        while(!q.empty()){
            auto t = q.front();
            q.pop();

            int stop = t.first;
            int n = t.second.first;
            int d = t.second.second;

            if(stop > k) continue;

            for(auto j : adj[n]){
                if((j.second + d < dist[j.first]) && (k+1 >= stop+1)){
                    dist[j.first] = j.second + d;
                    q.push({stop+1, {j.first, dist[j.first]} });
                }
            }
        }

        if(dist[dst] == INT_MAX) return -1;
        return dist[dst];
    }
};