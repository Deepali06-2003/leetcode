class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        
        int f =0,  r=0;
        int n = grid.size(), m = grid[0].size();
        queue<pair<int, int>>q;

        for(int i =0;i<n;i++){
            for(int j =0;j<m;j++){
                if(grid[i][j] == 1) f++;
                else if(grid[i][j] == 2){
                    r++;
                    q.push({i, j});
                }
            }
        }
        int ans=0;
        if(f == 0) return ans;

        vector<int>dx = {0 , 0, 1, -1};
        vector<int>dy = {1, -1, 0, 0};

        while(!q.empty()){
            int s = q.size();
            for(int i=0;i<s;i++){
                pair<int, int> temp = q.front();
                q.pop();

                for(int j =0;j<4;j++){
                    int nx = temp.first + dx[j];
                    int ny = temp.second + dy[j];

                    if(nx>=0 && ny>=0 && nx<n && ny<m && grid[nx][ny]==1){
                        grid[nx][ny]=2;
                        f--;
                        q.push({nx, ny});
                    }
                }
            }
            
            if(!q.empty()) ans++;
        }
        if(f==0)return ans;
        return -1;
    }
};

