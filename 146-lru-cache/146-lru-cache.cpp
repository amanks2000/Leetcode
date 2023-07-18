class Node {
public: 
    int key, val;
    Node* next, *prev;

    Node(int key, int val) {
        this->key = key;
        this->val = val;
        next = NULL;
        prev = NULL;
    }
};

class LRUCache {
public:
    int cnt = 0, cap;
    unordered_map<int, Node*> mp;
    Node *head, *tail;

    LRUCache(int capacity) {
        cap = capacity;
        head = new Node(0, 0);
        tail = new Node(0, 0);
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if(mp.count(key) == 0) 
            return -1;

        Node* cur = mp[key];
        int ans = cur->val;

        // create new node after head
        Node *newNode = new Node(key, ans);
        newNode->next = head->next;
        newNode->prev = head;
        newNode->next->prev = newNode;
        head->next = newNode;
        mp[key] = newNode;

        // delete node 
        cur->prev->next = cur->next;
        cur->next->prev = cur->prev;
        
        return ans;
    }
    
    void put(int key, int value) {
        Node *newNode = new Node(key, value);

        // inserting new node after head
        newNode->next = head->next;
        newNode->prev = head;
        newNode->next->prev = newNode;
        head->next = newNode;

        if(mp.count(key)) {
            Node* cur = mp[key];
            // delete cur
            cur->prev->next = cur->next;
            cur->next->prev = cur->prev;
            mp[key] = newNode;
            return;
        }
        // cout << head->next->key << " " << tail->prev->key << endl;
        if(cnt >= cap) {
            mp.erase(tail->prev->key);
            Node* lru = tail->prev;
            
            // delete lru node
            lru->prev->next = lru->next;
            lru->next->prev = lru->prev;
            cnt--;
        }

        mp[key] = newNode;
        cnt++;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */