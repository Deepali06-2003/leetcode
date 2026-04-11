class Solution {
public:

bool boxes(vector<vector<char>>& board , int sr , int sc, int er, int ec){
    set<int>st;
    for(int i =sr ; i<=er ; i++){
        for(int j=sc ; j<=ec ; j++){
            if(board[i][j]=='.')continue;
            if( st.find(board[i][j]) != st.end() )return false;
            st.insert(board[i][j]);
        }
    }
    return true;
}


    bool isValidSudoku(vector<vector<char>>& board) {
        set<int>st;

        for(int i =0;i<9;i++){
            st.clear();
            for(int j =0;j<9;j++){
                if(board[i][j]== '.')continue;
                if( st.find(board[i][j]) != st.end() )return false;
                st.insert(board[i][j]);
            }
        }

        for(int j =0;j<9;j++){
            st.clear();
            for(int i =0;i<9;i++){
                if(board[i][j]== '.')continue;
                if( st.find(board[i][j]) != st.end() )return false;
                st.insert(board[i][j]);
            }
        }
        return boxes(board,0, 0, 2, 2) && boxes(board,0, 3, 2, 5) && boxes(board,0, 6, 2, 8) &&
        boxes(board,3, 0, 5, 2)&& boxes(board,3, 3, 5, 5) && boxes(board,3, 6, 5, 8) &&
        boxes(board,6, 0, 8, 2)&& boxes(board,6, 3, 8, 5) && boxes(board,6, 6, 8, 8);
        
    }
};