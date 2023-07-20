class Solution {
public:
    vector<int> asteroidCollision(vector<int>& ast) {
        stack<int> st;

        for(auto it: ast) {
            if(it > 0)
                st.push(it);
            else {
                int flag = 1;
                while(!st.empty() && st.top() > 0) {
                    if(st.top() < -it)
                        st.pop();
                    else if(st.top() == -it) {
                        st.pop();
                        flag = 0;
                        break;
                    } 
                    else {
                        flag = 0;
                        break;
                    }
                }
                if(flag) st.push(it);
            }
        }

        vector<int> res;
        while(!st.empty()) {
            res.push_back(st.top());
            st.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};