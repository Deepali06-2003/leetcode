class Solution {
public:

    void solve(vector<vector<char>>& board) {

        int n = board.size() , m = board[0].size();

        queue<pair<int, int>>q;

        for(int i=0;i<n;i++){
            if(board[i][0] == 'O') q.push({i, 0});
            if(board[i][m-1] == 'O') q.push({i, m-1});
        }
        for(int j=0;j<m;j++){
            if(board[0][j]=='O') q.push({0, j});
            if(board[n-1][j]=='O') q.push({n-1, j});
        }

        vector<int> dx = {0 , 0 , 1, -1};
        vector<int>dy  = {1, -1, 0 , 0};
        
        while(!q.empty()){
            pair<int, int>temp = q.front();
            q.pop();

            if(temp.first<0 || temp.second<0 || temp.first>=n || temp.second>=m || board[temp.first][temp.second] !='O')    
                continue;

            board[temp.first][temp.second] = '#';            

            for(int j=0;j<4;j++){
                int nx = temp.first + dx[j];
                int ny = temp.second + dy[j];
                q.push({nx, ny});
            }
        }

        for(int i=0;i<n;i++){
            for(int j =0;j<m;j++){
                if(board[i][j] == '#') board[i][j] = 'O';
                else board[i][j] = 'X';
            }
        }

    }
};