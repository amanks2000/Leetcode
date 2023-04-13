class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> st;
        int n = pushed.size(), i = 0, j = 0;

        while(i < n && j < n) {
            st.push(pushed[i]);

            while(!st.empty() && j < n && st.top() == popped[j]) {
                st.pop();
                j++;
            }
            i++;
        }

        if(st.empty() && j == n) return true;
        return false;
    }
};