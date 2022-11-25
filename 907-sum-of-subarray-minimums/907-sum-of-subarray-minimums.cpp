class Solution {
public:
    int mod = 1e9 + 7;
    int sumSubarrayMins(vector<int>& arr) {
        unordered_map<int, int> nextLeft;
        unordered_map<int, int> nextRight;
        int n = arr.size();
        stack<pair<int, int>> st;

        st.push({INT_MIN, -1});
        st.push({arr[0], 0});
        nextLeft[0] = -1;

        // Get next smaller on left
        for(int i = 1; i < n; i++) {
            if(arr[i] > st.top().first) {
                auto p = st.top();
                nextLeft[i] = p.second;
            }
            else {
                while(st.top().first >= arr[i]) st.pop();
                auto p = st.top();
                nextLeft[i] = p.second;
            }
            st.push({arr[i], i});
        }
        while(!st.empty()) st.pop();

        st.push({INT_MIN, n});
        st.push({arr[n-1], n-1});
        nextRight[n-1] = n;

        // Get next smaller on right
        for(int i = n-2; i >= 0; i--) {
            if(arr[i] >= st.top().first) {
                auto p = st.top();
                nextRight[i] = p.second;
            }
            else {
                while(st.top().first > arr[i]) st.pop();
                auto p = st.top();
                nextRight[i] = p.second;
            }
            st.push({arr[i], i});
        }

        int ans = 0;
        for(int i = 0; i < n; i++) {
            // cout << arr[i] << " = " << nextLeft[i] << " " << nextRight[i] << endl;
            // cout << arr[i] << " -> " << (i - nextLeft[i]) * (nextRight[i] - i) << endl;
            long x = i - nextLeft[i];
            long y = nextRight[i] - i;
            long long val = (x * y * arr[i]) % mod;
            ans = (ans + val) % mod;
        }
        return ans;
    }
};