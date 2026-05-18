class Solution {
public:

    void solve(vector<vector<char>>& board) {

        int n = board.size() , m = board[0].size();

        queue<pair<int, int>>q;

       for(int i=0;i<n;i++){
        if(board[i][0] == 'O') q.push({i, 0});
        if(board[i][m-1] == 'O') q.push({i, m-1});
       }

        for(int i=0;i<m;i++){
        if(board[0][i] == 'O') q.push({0, i});
        if(board[n-1][i] == 'O') q.push({n-1, i});
       }

       vector<int>dx ={0, 0, 1, -1};
       vector<int>dy = {1, -1, 0, 0};

       while(!q.empty()){
        auto t = q.front();
        q.pop();

        if(t.first<0 || t.second<0 || t.first>=n || t.second>=m || board[t.first][t.second] != 'O')continue;

        board[t.first][t.second] = '#';

        for(int j =0;j<4;j++){
            int nx = t.first + dx[j];
            int ny = t.second + dy[j];

            q.push({nx, ny});
        }
       }

       for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(board[i][j] == '#') board[i][j] ='O';
            else board[i][j] ='X';
        }
       }




    }
};