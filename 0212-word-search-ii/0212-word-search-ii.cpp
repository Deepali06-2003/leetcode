class Solution {
public:
int n , m ;
vector<string>res;

struct Node{
    Node* child[26];
    bool endWord;
    string word;
    Node(){
        for(int i=0;i<26;i++)child[i]=NULL;
        endWord = false;
        word = "";
    }
};
void insert(Node* root , string& w){
    Node* temp = root;
    for(char c:w){
        if(temp->child[c-'a']==NULL) temp->child[c-'a'] = new Node();
        temp = temp->child[c-'a'];
    }
    temp->endWord = true;
    temp->word = w;
}
void dfs(Node* root , vector<vector<char>>& board,int i , int j){
    if(i<0 || i>=n ||j<0||j>=m)return;
    char c = board[i][j];
    if(c=='#'|| root->child[c-'a'] == NULL)return;
    
    root = root->child[c-'a'];
    if(root->endWord){
        res.push_back(root->word);
        root->endWord = false;
    }

    board[i][j] = '#';
    dfs(root , board , i+1, j);       dfs(root , board , i-1, j);     dfs(root , board , i, j+1);     dfs(root , board , i, j-1);
    board[i][j]=c;
}

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        res.clear();
        n = board.size(), m = board[0].size();

        Node* root = new Node();
        for(string& w : words)insert(root, w);

        for(int i =0;i<n;i++){
            for(int j =0;j<m;j++){
                dfs(root , board , i , j);
            }
        }
        return res;
    }
};