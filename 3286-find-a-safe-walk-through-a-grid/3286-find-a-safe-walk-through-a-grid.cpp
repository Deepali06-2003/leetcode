class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        
        int n = grid.size(), m = grid[0].size();

        queue<tuple<int, int, int>>q;
        vector<vector<int>>best_h(n , vector<int>(m, -1));

        health = health - grid[0][0];
        if(health < 1) return false;

        q.push({0, 0, health});
        best_h[0][0] = health;

        vector<int>dx = {0, 0, 1, -1};
        vector<int>dy = {1, -1, 0, 0};
        while(!q.empty()){

            auto [x, y, h] = q.front();
            q.pop();

            if(x == (n-1) && y ==(m-1)) return true;
            for(int j =0;j<4;j++){
                int nx = x+dx[j];
                int ny = y+dy[j];
                int nh = h;

                if(nx>=0 && nx<n && ny>=0 && ny<m){
                    nh = nh-grid[nx][ny];

                    if(nh<1)continue;
                    if(nh > best_h[nx][ny]){
                        q.push({nx, ny, nh});
                        best_h[nx][ny] = nh;
                    }

                }
            }
        }

        return false;
    }
};