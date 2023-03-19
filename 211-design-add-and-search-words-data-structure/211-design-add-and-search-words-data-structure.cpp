class Node {
public:
    Node* links[26];
    bool flag = false;
};

class WordDictionary {
public:
    Node* root;
    WordDictionary() {
        root = new Node();
    }
    
    void addWord(string word) {
        Node* cur = root;
        for(auto c: word) {
            if(!cur->links[c - 'a']) {
                cur->links[c - 'a'] = new Node();
            }
            cur = cur->links[c - 'a'];
        }
        cur->flag = true;
    }

    int n;
    bool helper(Node* cur, int ind, string& word) {
        if(ind == n) 
            return cur && cur->flag;

        if(word[ind] == '.') {
            for(int i = 0; i < 26; i++) {
                if(cur->links[i]) {
                    bool sm = helper(cur->links[i], ind + 1, word);
                    if(sm) return true;
                }
            }
        }
        else {
            if(cur->links[word[ind] - 'a'])
                return helper(cur->links[word[ind] - 'a'], ind + 1, word);
        }
        return false;
    }
    
    bool search(string word) {
        Node* cur = root;
        n = word.size();
        return helper(root, 0, word);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */