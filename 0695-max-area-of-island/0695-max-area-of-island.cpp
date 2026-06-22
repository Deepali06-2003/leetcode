class Solution {
public:
void helper(vector<vector<int>>& grid , int n , int m, int i , int j , int& c_ans){
    if(i<0 || j<0 || i>=n || j>=m || grid[i][j]!=1) return;

    grid[i][j]=0;
    c_ans++;

    helper(grid , n , m , i+1 , j , c_ans);
    helper(grid , n , m , i-1 , j , c_ans);
    helper(grid , n , m , i , j+1 , c_ans);
    helper(grid , n , m , i , j-1 , c_ans);
}
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();
        int ans=0;

        for(int i=0;i<n;i++){
            for(int j =0;j<m;j++){
                if(grid[i][j] == 1){
                    int c_ans =0;
                    helper(grid , n , m , i , j, c_ans);
                    ans = max(ans , c_ans);
                }
            }
        }
        return ans;
    }
};


