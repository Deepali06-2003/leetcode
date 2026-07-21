class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int, int>>q;
        int f=0, r=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({i, j});
                    r++;
                }
                else if(grid[i][j]==1) f++;
            }
        }
        if(f==0) return 0;

        int ans=0;
        vector<int>dx = {1, -1, 0, 0};
        vector<int>dy = {0,0, 1, -1};

        while(!q.empty()){

            int sz = q.size();
            for(int i=0;i<sz ;i++)
            {
                auto temp = q.front();
                q.pop();

                for(int j=0;j<4;j++){
                    int nx = temp.first + dx[j];
                    int ny = temp.second + dy[j];

                    if(nx>=0 && ny>=0 && nx<n && ny<m && grid[nx][ny]==1){
                        q.push({nx, ny});
                        f--;
                        grid[nx][ny]=2;
                    }
                }
            }
            ans= ans+1;
            if(f==0)return ans;
        }
        return (f==0)? ans : -1;
    }
};