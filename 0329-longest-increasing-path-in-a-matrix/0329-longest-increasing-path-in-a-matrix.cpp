class Solution {
public:

int helper(vector<vector<int>>& matrix , vector<vector<int>>& dp, int n, int m , int i , int j){
    if(dp[i][j] != 0)return dp[i][j];

    vector<int>dx = {0, 0, 1, -1};
    vector<int>dy = {1, -1, 0,0};

    int c=1;
    for(int x = 0;x<4;x++){
        int nx = i+dx[x];
        int ny = j+dy[x];

        if(nx>=0 && ny>=0 && nx<n && ny<m && matrix[nx][ny]>matrix[i][j]){
            c = max(c , 1+helper(matrix , dp , n, m, nx, ny));
        }
    }
    dp[i][j] = c;
    return c;
}
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        
        int n = matrix.size() ,m= matrix[0].size();
        vector<vector<int>> dp(n, vector<int>(m , 0));
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                ans = max(ans , helper(matrix , dp , n, m, i, j));
            }
        }
        return ans;
    }
};