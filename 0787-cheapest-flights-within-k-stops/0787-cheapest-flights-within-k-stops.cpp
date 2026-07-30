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

        q.push({0, {src,0}});
        dist[src]=0;

        while(!q.empty()){
            auto t = q.front();
            q.pop();

            int stop = t.first , node = t.second.first , c_d = t.second.second;;

            if(stop > k) continue;

            for(auto j : adj[node]){
                int n = j.first;
                int d = j.second;

                if(c_d+d < dist[n] && stop+1 <=k+1){
                    dist[n] = c_d+d;
                    q.push({stop+1 , {n, dist[n]}});
                }
            }
        }
        if(dist[dst] == INT_MAX) return -1;
        return dist[dst];

    }
};