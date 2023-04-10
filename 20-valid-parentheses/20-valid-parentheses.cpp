class Solution {
public:
    bool isValid(string s) {
        int n = s.size();
        stack<char> st;
        
        for(auto c: s) {
            if(c == '(' || c == '[' || c == '{') 
                st.push(c);
            else if(c == ')') {
                if(!st.empty() && st.top() == '(') st.pop();
                else return false;
            }
            else if(c == ']') {
                if(!st.empty() && st.top() == '[') st.pop();
                else return false;
            }
            else if(c == '}') {
                if(!st.empty() && st.top() == '{') st.pop();
                else return false;
            }
        }
        
        if(st.empty()) return true;
        else return false;
    }
};