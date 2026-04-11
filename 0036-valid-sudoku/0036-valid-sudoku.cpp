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

        for(int sr =0;sr<9; sr += 3){
            int er = er+2;
            for(int sc =0;sc<9;sc+= 3){
                int ec = ec+2;

                bool x = boxes(board , sr , sc , er , ec);
                if(x== false)return false;
            }
        }

        return true;
        
    }
};