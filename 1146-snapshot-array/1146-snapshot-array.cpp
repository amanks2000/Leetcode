class SnapshotArray {
public:
    int count = 0;
    unordered_map<int, map<int, int> > mp; // index -> snap_ids, val

    SnapshotArray(int length) {
    }
    
    void set(int index, int val) {
        mp[index][count] = val;
    }
    
    int snap() {
        count++;
        return count - 1;
    }
    
    int get(int index, int snap_id) {
        if(mp.count(index) == 0)
            return 0;

        auto it = mp[index].upper_bound(snap_id);
        if(it == mp[index].begin())
            return 0;
        return prev(it)->second;
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */