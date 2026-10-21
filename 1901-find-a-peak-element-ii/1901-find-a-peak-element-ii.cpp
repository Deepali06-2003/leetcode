class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        
        int n = mat.size();
        int m = mat[0].size();          



        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {

                if ((i == 0 || mat[i][j] > mat[i-1][j]) &&
                    (i == n-1 || mat[i][j] > mat[i+1][j]) &&
                    (j == 0 || mat[i][j] > mat[i][j-1]) &&
                    (j == m-1 || mat[i][j] > mat[i][j+1])) {

                    return {i, j};
                }
            }
        }
        return {-1, -1};
    }
};