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

              priority_queue<
    pair<int, pair<int,int>>,
    vector<pair<int, pair<int,int>>>,
    greater<pair<int, pair<int,int>>>
> pq;
        vector<vector<int>> cost(n, vector<int>(k + 2, INT_MAX));

        pq.push({0, {src, 0}});
        cost[src][0] =0;

        while(!pq.empty()){
            auto temp = pq.top();
            pq.pop();

            int c = temp.first , n = temp.second.first , stops = temp.second.second;;

            if(n == dst) return c;
            if(stops == k+1) continue;

            for(auto j: adj[n]){
                int curr_c = c + j.second;

                if(curr_c < cost[j.first][stops+1]) {
                    cost[j.first][stops+1] = curr_c;
                    pq.push({curr_c , {j.first , stops+1}});
                }
            }
        }
        return -1;

    }
};