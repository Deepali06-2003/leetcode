class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        
        vector<vector<int>>dist(n, vector<int>(n, INT_MAX));
        
        for(int i=0;i<edges.size();i++){
            int u = edges[i][0], v = edges[i][1], wt = edges[i][2];
            dist[u][v] = wt;
            dist[v][u] = wt;
        }

        for(int k=0;k<n;k++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){

                    if(i==j) dist[i][j]=0;
                    else if(dist[i][k]==INT_MAX || dist[k][j]==INT_MAX) continue;
                    else dist[i][j] = min(dist[i][j] , dist[i][k]+ dist[k][j]);
                }
            }
        }

        int min_c = INT_MAX , ans=0;
        for(int i=0;i<n;i++){
            int c=0;
            for(int j=0;j<n;j++){
                if(dist[i][j] <= distanceThreshold) c++;
            }

            if(min_c >= c){
                min_c = c;
                ans = i;
            }
        }
        return ans;
    }
};