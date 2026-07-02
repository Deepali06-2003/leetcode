class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        
        int n = grid.size(), m = grid[0].size();

        int startHealth = health - grid[0][0];
        if(startHealth < 1) return false;

        queue<tuple<int,int,int>> q;
        q.push({0, 0, startHealth});

        vector<vector<int>> best(n, vector<int>(m, -1));
        best[0][0] = startHealth;

        vector<int>dx = {0, 0, 1, -1};
        vector<int>dy = {1, -1, 0, 0};

        while(!q.empty()){
            auto [x, y, h] = q.front();
            q.pop();

            if(x == n-1 && y== m-1 && h>=1) return true;

            for(int j = 0;j<4;j++){
                int nx = x + dx[j];
                int ny = y + dy[j];
                int nh = h;

                if(nx>=0 && ny>=0 && nx<n && ny<m ){
                    nh = nh - grid[nx][ny];
                    if(nh<1)continue;
                    //updating health if new health
                    if(nh > best[nx][ny]) {
                        best[nx][ny] = nh;
                        q.push({nx, ny, nh});
                    }
                }
            }
        }

        return false;
    }
};