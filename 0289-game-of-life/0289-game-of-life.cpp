class Solution {
public:
void helper(vector<vector<int>>& board ,vector<vector<int>>& temp, int n , int m, int i, int j, int c){

    vector<int>dx = {0, 0, 1, -1, -1, -1, 1, 1};
    vector<int>dy = {1, -1, 0 , 0, -1, 1 , -1 , 1};

    for(int x = 0 ;x<8;x++){
        int nx = i+dx[x];
        int ny = j+dy[x];

        if(nx>=0 && ny>=0 && nx<n && ny<m && board[nx][ny]==1) c++;
    }
    if(board[i][j]==1){
        if(c==2 || c==3) temp[i][j] = 1;
        else temp[i][j] = -1;
    }
    else{
        if(c==3) temp[i][j] = 2;
        else temp[i][j] = 0;
    }

}
    void gameOfLife(vector<vector<int>>& board) {

        int n = board.size() , m = board[0].size();
        vector<vector<int>>temp(n ,vector<int>(m, 0));

        for(int i =0;i<n;i++){
            for(int j =0;j<m;j++){
                int c=0;
                helper(board ,temp, n , m , i , j , c);
            }
        }

        for(int i =0;i<n;i++){
            for(int j=0;j<m;j++){
                if(temp[i][j]==1 || temp[i][j]==2) board[i][j] =1;
                else board[i][j] =0;
            }
        }
    }
};