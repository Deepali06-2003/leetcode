class Solution {
public:

bool isValid(vector<string>& board , int r, int c, int n){
    int row = r, col =c;

    while(r>=0 && c>=0){
        if(board[r][c]=='Q') return false;
        r--;
        c--;
    }
    r = row;
    c= col;

    while(c>=0){
        if(board[r][c]=='Q') return false;
        c--;
    }
    r = row;
    c= col;

    while(r<n && c>=0){
        if(board[r][c]=='Q') return false;
        r++;
        c--;
    }
    return true;
}
void helper(int n ,vector<vector<string>>& res, vector<string>& board, int col ){

    if(col == n){
        res.push_back(board);
        return;
    }

    for(int r = 0;r<n;r++){
        if(isValid(board , r, col, n)){
            board[r][col]='Q';
            helper(n, res, board, col+1);
            board[r][col]='.';
        }
    }
}
    vector<vector<string>> solveNQueens(int n) {
        
        vector<string> board(n, string(n, '.'));

        vector<vector<string>>res;
        helper(n , res, board , 0);
        return res;

    }
};