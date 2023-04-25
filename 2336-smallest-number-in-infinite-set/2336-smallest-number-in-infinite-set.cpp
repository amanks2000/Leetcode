class SmallestInfiniteSet {
public:
    unordered_map<int, int> removed;
    SmallestInfiniteSet() {
        
    }
    
    int popSmallest() {
        int num = 1;
        while(true) {
            if(!removed[num]) {
                removed[num] = 1;
                return num;
            }
            num++;
        }
        return 0;
    }
    
    void addBack(int num) {
        removed[num] = 0;
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */