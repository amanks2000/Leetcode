class Solution {
public:
    int partitionString(string s) {
        int cnt = 1, i = 0, n = s.size();
        unordered_set<char> st;
        
        while(i < n) {
            if(st.count(s[i])) {
                cnt++;
                st.clear();
            } 
            
            st.insert(s[i]);
            i++;
        }
        
        return cnt;
    }
};