class Solution {
public:
bool helper(vector<vector<char>>& board, string word , int n , int m , int i , int j, int s){
    if(s == word.size())return true;
    if(i<0 || i>=n || j<0 || j>=m || board[i][j]!=word[s])return false;

    char x = board[i][j];
    board[i][j]='$';

    bool f = helper(board, word, n, m , i+1, j, s+1) || helper(board, word, n, m , i-1, j, s+1) || helper(board, word, n, m , i, j+1, s+1) || helper(board, word, n, m , i, j-1, s+1) ;

    board[i][j]= x;
    return f;
}

    bool exist(vector<vector<char>>& board, string word) {
        
        int n = board.size();
        int m = board[0].size();

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j] == word[0]){
                    if(helper(board , word , n , m ,i , j, 0))return true;
                }
            }
        }
        return false;
    }
};