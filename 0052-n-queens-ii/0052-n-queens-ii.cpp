class Solution {
public:
bool isSafe(vector<string>& board , int r , int c, int n ){
    int row =r , col = c;

    while(r>=0 && c>=0){
        if(board[r][c]=='Q')return false;
        r--; c--;
    }
    r = row , c = col;
    while(c>=0){
        if(board[r][c]=='Q')return false;
        c--;
    }
    r = row , c = col;
    while(r<n && c>=0){
        if(board[r][c]=='Q')return false;
        r++; c--;
    }
    return true;
}

void helper(int & ans , vector<string>& board , int n , int c){

    if(c == n){
        ans++;
        return;
    }
    for(int r =0 ;r<n;r++){
        if(isSafe(board , r , c , n)){
            board[r][c] = 'Q';
            helper(ans , board , n , c+1);
            board[r][c] ='.';
        }
    }
}
    int totalNQueens(int n) {
        int ans =0;
         
        vector<string>board(n);
        string s(n , '.');

        for(int i=0;i<n;i++)board[i]=s;

        helper(ans , board , n , 0);
        return ans;
    }
};