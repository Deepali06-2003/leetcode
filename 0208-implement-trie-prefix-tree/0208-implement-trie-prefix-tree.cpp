class Trie {
public:
struct Node{
    Node* child[26];
    bool endWord;

    Node(){
        for(int i =0;i<26;i++)child[i]=NULL;
        endWord = false;
    }
};
Node* root;
    Trie() {
        root = new Node();
    }
    
    void insert(string word) {
        Node* temp = root;
        for(char c : word){
            if(temp->child[c-'a'] == NULL) temp->child[c-'a'] = new Node();
            temp = temp->child[c-'a'];
        }
        temp->endWord = true;
    }
    
    bool search(string word) {
        Node* temp = root;
        for(char c: word){
            if(temp->child[c-'a'] == NULL)return false;
            temp = temp->child[c-'a'];
        }
        if(temp->endWord == true)return true;
        return false;
    }
    
    bool startsWith(string prefix) {
         Node* temp = root;
         for(char c: prefix){
            if(temp->child[c-'a'] == NULL)return false;
            temp = temp->child[c-'a'];
         }
         return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */