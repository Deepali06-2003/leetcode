class Solution {
public:
void bfs(vector<vector<bool>>&arr , queue<pair<int, int>>& q, vector<vector<int>>& heights){
    int n = heights.size();
    int m = heights[0].size();

    vector<int>dx = {0, 0, 1, -1};
    vector<int>dy = {1, -1, 0, 0};

    while(!q.empty()){

        pair<int,int> temp = q.front();
        q.pop();

        for(int j =0;j<4;j++){
            int nx = temp.first + dx[j];
            int ny = temp.second + dy[j];

            if(nx>= 0 && ny>=0 && nx<n && ny<m && arr[nx][ny]==false && heights[nx][ny] >= heights[temp.first][temp.second]){
                q.push({nx , ny});
                arr[nx][ny] = true;
            }
        }
    }


}

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        
        int n = heights.size();
        int m = heights[0].size();

        vector<vector<bool>>pac (n, vector<bool>(m, false));
        vector<vector<bool>>atl (n, vector<bool>(m, false));

        queue<pair<int, int>> atl_q;
        queue<pair<int, int>> pac_q;

        for(int i=0;i<n;i++){
            pac_q.push({i,0});
            pac[i][0]=true;

            atl_q.push({i, m-1});
            atl[i][m-1]= true;
        }

        for(int i=0;i<m;i++){
            pac_q.push({0,i});
            pac[0][i]=true;

            atl_q.push({n-1, i});
            atl[n-1][i]= true;
        }

        bfs(pac , pac_q, heights);
        bfs(atl , atl_q, heights);

        vector<vector<int>>res;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(pac[i][j] && atl[i][j]) res.push_back({i, j});
            }
        }
        return res;
    }
};