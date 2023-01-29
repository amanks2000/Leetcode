class Node {
public: 
    int key, val, cnt;
    Node* next, *prev;

    Node(int key, int val) {
        this->key = key;
        this->val = val;
        next = NULL;
        prev = NULL;
        cnt = 1;
    }
};

class List {
public:
    Node *head, *tail;
    int size;

    List() {
        head = new Node(0, 0);
        tail = new Node(0, 0);
        head->next = tail;
        tail->next = head;
        size = 0;
    }

    void insertNode(Node *newNode) {
        newNode->next = head->next;
        newNode->prev = head;
        newNode->next->prev = newNode;
        head->next = newNode;
        size++;
    }

    void deleteNode(Node* cur) {
        cur->prev->next = cur->next;
        cur->next->prev = cur->prev;
        size--;
    }
};

class LFUCache {
public:
    unordered_map<int, List*> freqList;
    unordered_map<int, Node*> mp;
    int cap, cnt, minFreq;

    LFUCache(int capacity) {
        cap = capacity;
        cnt = 0;
        minFreq = 0;
    }

    void updateList(Node* node) {
        mp.erase(node->key);
        int curFreq = node->cnt;
        freqList[curFreq]->deleteNode(node);

        if(curFreq == minFreq && freqList[curFreq]->size == 0) 
            minFreq++;

        List *newList = new List();
        if(freqList.count(curFreq + 1) != 0) 
            newList = freqList[curFreq + 1];

        node->cnt += 1;
        curFreq++;

        newList->insertNode(node);
        freqList[curFreq] = newList;
        mp[node->key] = node;
    }
    
    int get(int key) {
        if(mp.count(key) == 0)
            return -1;

        Node* node = mp[key];
        int ans = mp[key]->val;
        updateList(node);
        return ans;
    }
    
    void put(int key, int value) {
        if(cap == 0) 
            return;

        if(mp.count(key)) {
            Node* node = mp[key];
            node->val = value;
            updateList(node);
            return;
        }
        if(cnt == cap) {
            // delete LRU from freqList with minFreq
            List* list = freqList[minFreq];
            mp.erase(list->tail->prev->key); // erase last node
            freqList[minFreq]->deleteNode(list->tail->prev);
            cnt--;
        }

        minFreq = 1;

        List* list = new List();
        if(freqList.count(minFreq) == 1)
            list = freqList[minFreq];

        // Inserting new node at min frequency List
        Node* newNode = new Node(key, value);
        list->insertNode(newNode);
        mp[key] = newNode;
        freqList[minFreq] = list;

        cnt++;
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */