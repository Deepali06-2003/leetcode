class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
    
        int n = matrix.size();
        vector<vector<int>>dp(n, vector<int>(n , 0));

        for( int i =0;i<n;i++){
            for(int j =0;j<n;j++){
                dp[j][n-1-i] = matrix[i][j];
            }
        }   
        for( int i =0;i<n;i++){
            for(int j =0;j<n;j++){
                matrix[i][j] = dp[i][j];
            }
        }  
    }
};