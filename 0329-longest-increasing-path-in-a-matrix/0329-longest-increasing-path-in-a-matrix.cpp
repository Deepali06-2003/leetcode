class Solution {
public:


int helper(vector<vector<int>>& matrix ,int n , int m , int i , int j, vector<vector<int>>& dp ){
    if(dp[i][j] != 0)return dp[i][j];

    int dir[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};

    int curr =1;
    for(auto& d : dir){
        int nx = i+d[0];
        int ny =j+d[1];

        if(nx>= 0 && nx<n && ny>= 0 && ny<m && matrix[nx][ny] > matrix[i][j]){
            curr = max(curr , 1+helper(matrix , n , m , nx , ny, dp) );
        }
    }
    dp[i][j] = curr;
    return curr;
}

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int ans =0;

        vector<vector<int>>dp(n , vector<int>(m , 0));
        
        for(int i =0;i<n;i++){
            for(int j =0;j<m;j++){
                ans = max(ans, helper(matrix , n , m , i, j , dp));
            }
        }
        return ans;
    }
};