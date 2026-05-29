class Trie {
private:    
    struct Node {
        Node* son[26]{};
        bool end = false;
    };
    Node* root;
    int find(const string& word) {
        Node* cur = root;
        for(char c: word) {
            c -= 'a';
            if(cur->son[c] == nullptr) {
                return 0;
            }
            cur = cur->son[c];
        }
        // 2 - completely same, 1 - prefix matched
        return cur->end ? 2 : 1;
    }
    void destory(Node* node) {
        if(node == nullptr) {
            return;
        }
        for(Node* son: node->son) {
            destory(son);
        }
        delete node;
    }
public:
    Trie() {
        root = new Node();
    }
    ~Trie() {
        destory(root);
    }
    
    void insert(string word) {
        Node* cur = root;
        for(char c: word) {
            c -= 'a';
            if(cur->son[c] == nullptr) {
                cur->son[c] = new Node();
            }
            cur = cur->son[c];
        }
        cur->end = true;
    }
    
    bool search(string word) {
        return find(word) == 2;
    }
    
    bool startsWith(string prefix) {
        return find(prefix) != 0;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */