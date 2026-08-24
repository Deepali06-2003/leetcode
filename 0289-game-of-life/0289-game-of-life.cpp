class Solution {
public:

int helper(vector<vector<int>>& dp, int i, int j, int n, int m){
    int c=0;

    vector<int>dx = {0, 0, 1, -1, -1, -1, 1, 1};
    vector<int>dy = {1, -1, 0 , 0, -1, 1 , -1 , 1};
    for(int x=0;x<8;x++){
        int nx = dx[x]+i;
        int ny = dy[x]+j;

        if(nx>=0 && ny>=0 && nx<n && ny<m && dp[nx][ny]==1) c++;
    }

    if(dp[i][j]==1){
        if(c==2 || c==3) return 1;
        else return 0;
    }
    else{
        if(c==3) return 1;
        return 0;
    }
}
    void gameOfLife(vector<vector<int>>& board) {

     int n = board.size(), m = board[0].size();
     vector<vector<int>>dp(n, vector<int>(m , 0));

        dp = board;
     for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){

           board[i][j]= helper(dp, i, j , n , m);
        }
     }  

    }
};