class Node {
public: 
    Node* links[26];
    bool flag = false;
};

class Trie {
public:
    Node* root;
    Trie() {
        root = new Node();
    }
    
    void insert(string word) {
        Node* cur = root;
        for(auto c: word) {
            if(cur->links[c-'a'] == NULL) {
                // Character not present, therefore create a new node
                cur->links[c-'a'] = new Node();
            }
            cur = cur->links[c-'a'];
        }
        cur->flag = true; // end of word flag is set
    }
    
    bool search(string word) {
        Node* cur = root;
        for(auto c: word) {
            if(cur->links[c-'a'] == NULL) 
                return false;
            cur = cur->links[c-'a'];
        }
        if(cur->flag) return true;
        else return false;
    }
    
    bool startsWith(string prefix) {
        Node* cur = root;
        for(auto c: prefix) {
            if(cur->links[c-'a'] == NULL) 
                return false;
            cur = cur->links[c-'a'];
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