struct TreePoint{
    TreePoint* children[26];
    bool isEnd = false;
    
    TreePoint(){
        for(int i = 0; i < 26; i++){
            children[i] = nullptr;
        }
    }
};

class Trie {
public:
    TreePoint* root = new TreePoint();

    Trie() {
        return;
    }
    
    void insert(string word) {
        TreePoint* node = root;

        for(char a: word){
            int eh = a - 'a';

            if(!node->children[eh]){
                TreePoint* newnew = new TreePoint();
                node->children[eh] = newnew;
            }
            node = node->children[eh];
        }
        node->isEnd = true;
    }
    
    bool search(string word) {
        TreePoint* node = root;

        for(char a:word){
            int eh = a-'a';

            if(!node->children[eh]){
                return false;
            }
            node = node->children[eh];
        }
        return node->isEnd;
    }
    
    bool startsWith(string prefix) {
        TreePoint* node = root;

        for(char a:prefix){
            int eh = a-'a';

            if(!node->children[eh]){
                return false;
            }
            node = node->children[eh];
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