#define ll long long

class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        int n = costs.size();
        int l = 0, r = n - 1;

        priority_queue<int, vector<int>, greater<int>> left, right;
        while(l < candidates && l <= r) {
            left.push(costs[l++]);
            if(l-1 != r) right.push(costs[r--]);
        }
        
        ll res = 0;
        while(k--) {
            if(left.size() && right.size()) {
                int l_top = left.top();
                int r_top = right.top();

                if(l_top <= r_top) {
                    left.pop();
                    if(l <= r) left.push(costs[l++]);
                    res += l_top;
                }
                else {
                    right.pop();
                    if(r >= l) right.push(costs[r--]);
                    res += r_top;
                }
            }
            else if(left.size()) {
                res += left.top();
                left.pop();
            }
            else if(right.size()) {
                res += right.top();
                right.pop();
            }
        }
        return res;
    }
};