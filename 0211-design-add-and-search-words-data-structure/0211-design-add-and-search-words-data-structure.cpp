class WordDictionary {
public:
struct Node{
    Node* child[26];
    bool endWord;
    Node(){
        for(int i =0;i<26;i++)child[i]=NULL;
        endWord = false;
    }
};
Node* root ;
    WordDictionary() {
        root = new Node();
    }
    
    void addWord(string word) {
        Node* temp = root;
        for(char c:word){
            if(temp->child[c-'a'] == NULL)temp->child[c-'a'] = new Node();
            temp = temp->child[c-'a'];
        }
        temp->endWord = true;
    }
    bool helper(string word , Node* root){
        Node* temp = root;
        for(int i =0;i<word.size(); i++){
            char c = word[i];
            if(c == '.'){
                for(int j =0;j<26;j++){
                    if(temp->child[j] != NULL){
                        if(helper(word.substr(i+1) , temp->child[j] ))return true;
                    }
                }return false;
            }

            if(temp->child[c-'a'] == NULL)return false;
            temp = temp->child[c-'a'];
        }
        return (temp->endWord)?true : false;
    }

    bool search(string word) {
        return helper(word , root);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */