class Solution {
public:
void helper(vector<vector<int>>& heights,queue<pair<int, int>>& q, vector<vector<bool>>& arr){
    int n = heights.size();
    int m = heights[0].size();
    vector<int>dx = {0, 0, 1, -1};
    vector<int>dy = {1, -1, 0, 0};

    while(!q.empty()){
        pair<int, int> t = q.front();
        q.pop();

        for(int j =0;j<4;j++){
            int nx = t.first + dx[j];
            int ny = t.second + dy[j];

            if(nx>=0 && ny>=0 && nx<n && ny<m && heights[t.first][t.second] <= heights[nx][ny] && arr[nx][ny]==false ){
                q.push({nx, ny});
                arr[nx][ny] = true;
            }
        }
    }
}
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {

        int n = heights.size();
        int m = heights[0].size();
        
        vector<vector<bool>> pac(n , vector<bool>(m , false));
        vector<vector<bool>> atl(n , vector<bool>(m , false));

        queue<pair<int, int>> atl_q;
        queue<pair<int, int>> pac_q;

        for(int i =0;i<n;i++){
            pac_q.push({i, 0});
            pac[i][0] = true;

            atl[i][m-1] = true;
            atl_q.push({i, m-1});
        }

        for(int j =0;j<m;j++){
            pac_q.push({0, j});
            pac[0][j] = true;

            atl[n-1][j] = true;
            atl_q.push({n-1 , j});
        }

        helper(heights , pac_q , pac );
        helper(heights, atl_q , atl );

        vector<vector<int>>res;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(pac[i][j]==true && atl[i][j]==true)
                    res.push_back({i, j});
            }
        }
        return res;
    }
};