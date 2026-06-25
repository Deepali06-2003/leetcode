class Solution {
public:

bool helper(vector<vector<char>>& board, string& word , int n , int m , int i , int j, int x){
    if(x == word.size())return true;
    if(i<0 || j<0 || i>=n || j>=m || board[i][j]!=word[x])return false;

    char temp = board[i][j];
    board[i][j]= '*';

    bool w = helper(board, word , n , m , i+1 , j , x+1) || helper(board, word , n , m , i-1 , j , x+1) || helper(board, word , n , m , i , j+1 , x+1) || helper(board, word , n , m , i , j-1 , x+1);

    board[i][j] = temp;
    return w;
}


    bool exist(vector<vector<char>>& board, string word) {
        
        int n = board.size() , m = board[0].size();

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                
                if(board[i][j] == word[0]){
                    if(helper(board, word , n , m , i , j , 0))return true;
                }
            }
        }
        return false;
    }
};