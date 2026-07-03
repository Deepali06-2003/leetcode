class Trie {
public:

struct Node{
    Node* child[26];
    bool endW;

    Node(){
        endW = false;
        for(int i=0;i<26;i++) child[i] = NULL;
    }
};

Node* root;
    Trie() {
        root = new Node();
    }
    
    void insert(string word) {
        Node* t = root;
        for(char c: word){
            if(t->child[c-'a'] == NULL)
                t->child[c-'a'] = new Node();
            t = t->child[c-'a'];
        }
        t->endW = true;
    }
    
    bool search(string word) {
        Node* t = root;
        for(char c: word){
            if(t->child[c-'a'] == NULL)
                return false;
            t = t->child[c-'a'];
        }
        if(t->endW) return true;
        return false;
    }
    
    bool startsWith(string prefix) {
        Node* t = root;
        for(char c: prefix){
            if(t->child[c-'a'] == NULL)
                return false;
            t = t->child[c-'a'];
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