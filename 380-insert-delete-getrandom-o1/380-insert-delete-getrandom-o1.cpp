class RandomizedSet {
public:
    unordered_set<int> s;
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(s.find(val) != s.end())
            return false;
        s.insert(val);
        return true;
    }
    
    bool remove(int val) {
        if(s.find(val) == s.end())
            return false;
        s.erase(val);
        return true;
    }
    
    int getRandom() {
        int randIndex = rand() % s.size();
        for(auto it: s) {
            if(randIndex == 0)
                return it;
            randIndex--;
        }

        return -1;
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */