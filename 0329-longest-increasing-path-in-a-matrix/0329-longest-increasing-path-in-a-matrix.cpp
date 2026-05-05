class Solution {
public:

int helper(vector<vector<int>>& matrix, vector<vector<int>>& dp , int n , int m , int i, int j){
    if(dp[i][j] != 0)return dp[i][j];

    int dir[4][2] = {{0,1}, {1,0}, {0,-1}, {-1,0}};
    int c=1;
    for(auto d: dir){
        int x= i+d[0];
        int y = j+d[1];

        if(x>=0 && y>=0 && x<n && y<m && matrix[x][y] > matrix[i][j]){
            c = max(c , 1+helper(matrix, dp, n , m, x, y));
        }
    }

    dp[i][j]= c;
    return c;
}
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        
        int n = matrix.size(), m = matrix[0].size();

        vector<vector<int>> dp(n , vector<int>(m , 0));
        int ans=0;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){

                ans = max(ans , helper(matrix , dp , n , m , i , j));
            }
        }
        return ans;
    }
};