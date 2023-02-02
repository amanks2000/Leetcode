class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        string prev = words[0];
        for(int i = 1; i < words.size(); i++) {
            string cur = words[i]; int flag = 0;
            for(int j = 0; j < min(prev.size(), cur.size()); j++) {
                if(prev[j] != cur[j]) {
                    flag = 1;
                    int ip = order.find(prev[j]);
                    int ic = order.find(cur[j]);
                    if(ip > ic) return false;
                    else break;
                }
            }
            if(flag == 0) {
                if(cur.size() < prev.size()) return false;
            } 
            prev = cur;
        }
        return true;
    }
};