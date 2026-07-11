class Solution {
public:

bool IsPath(vector<vector<int>>& grid, int m, int n){

    vector<vector<int>> visited(n, vector<int>(n, -1));
    queue<pair<int, int>>q;

    if(grid[0][0] < m) return false;

    q.push({0, 0});
    visited[0][0] = 1;

    vector<int>dx = {1, -1, 0, 0};
    vector<int>dy = {0, 0, 1, -1};

    while(!q.empty()){
        auto temp = q.front();
        q.pop();

        if(temp.first == n-1 && temp.second == n-1) return true;

        for(int j=0;j<4;j++){
            int nx = temp.first + dx[j];
            int ny = temp.second + dy[j];

            if(nx>=0 && ny>=0 && nx<n && ny<n && visited[nx][ny]==-1 && grid[nx][ny]>=m){
                q.push({nx, ny});
                visited[nx][ny] = 1;
            }
        }
    }
    return false;
}

    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n = grid[0].size();
        if(grid[0][0]==1 || grid[n-1][n-1]==1) return 0;

        // getting thief index
        queue<pair<int, int>>q;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    q.push({i,j});
                    grid[i][j]=0;
                }
                else grid[i][j]= INT_MAX;
            }
        }

        vector<int>dx = {1, -1, 0, 0};
        vector<int>dy = {0, 0, 1, -1};

        //cal dis of box  
        while(!q.empty()){
            auto t = q.front();
            q.pop();

            for(int j=0;j<4;j++){
                int nx = t.first + dx[j];
                int ny = t.second + dy[j];

                if(nx>=0 && ny>=0 && nx<n && ny<n && grid[nx][ny] == INT_MAX){
                    grid[nx][ny] = grid[t.first][t.second] + 1;
                    q.push({nx, ny});
                }
            }
        }



        int ans = 0;
        int l = 1, h = 2*n;

        while(l<=h){
            int m = (l+h)/2;

            if(IsPath(grid, m, n)){
                ans = m;
                l = m+1;
            }
            else h = m-1;
        }
        
        return ans;
    }
};