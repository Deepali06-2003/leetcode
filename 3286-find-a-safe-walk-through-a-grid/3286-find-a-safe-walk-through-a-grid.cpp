class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        
        int n = grid.size();
        int m = grid[0].size();

        int h = health;
        h = h - grid[0][0];

        if(h<1) return false;

        queue<tuple<int, int, int>>q;
        vector<vector<int>> best_h(n, vector<int>(m , 0));
        vector<int>dx = {0, 0, 1, -1};
        vector<int>dy = {1, -1, 0, 0};

        q.push({0, 0, h});
        best_h[0][0] = h;

        while(!q.empty()){
            auto[x, y, z] = q.front();
            q.pop();

            if(x == n-1 && y == m-1) return true;
            
            for(int j=0;j<4;j++){
                int nx = x+ dx[j];
                int ny = y + dy[j];

                if(nx>=0 && ny>=0 && nx<n && ny<m){
                    int nh = z - grid[nx][ny];

                    if(nh > best_h[nx][ny]){
                        best_h[nx][ny] = nh;
                        q.push({nx, ny, nh});
                    }
                }
            }
        }

        return false;
    }
};