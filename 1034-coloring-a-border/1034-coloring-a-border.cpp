class Solution {
public:
    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int row, int col, int color) {
        int n = grid.size();
        int m = grid[0].size();

        queue<pair<int, int>>q;

        vector<int>dx = {0, 0, 1, -1};
        vector<int>dy = {1, -1, 0, 0};
        vector<pair<int, int>>border;

        q.push({row, col});
        int old_c = grid[row][col];
        grid[row][col] = -1;

        while(!q.empty()){

            auto j = q.front();
            q.pop();

            int a = j.first , b = j.second;

           for(int x = 0;x<4;x++){
            int nx = a+ dx[x];
            int ny = b+ dy[x];

            // out of range
            if(nx<0 || ny<0 || nx>= n || ny>=m){
                border.push_back({a, b});
            }
            // already visited
            else if(grid[nx][ny] == -1){
                continue;
            }
            //if boundary meet
            else if(grid[nx][ny] != old_c){
                border.push_back({a, b});
            }
            else{
                q.push({nx, ny});
                grid[nx][ny]=-1;
            }
           }
        }

        for(auto j: border){
            int x = j.first, y = j.second;

            grid[x][y]=color;
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==-1) grid[i][j] = old_c;
            }
        }
        return grid;
    }
};