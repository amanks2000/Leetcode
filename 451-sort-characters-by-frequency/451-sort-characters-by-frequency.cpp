class Solution {
public:
    string frequencySort(string s) {
        vector<pair<int, char>> vec;
        for(int i = 0; i < 75; i++) {
            char c = char(i + '0');
            vec.push_back({0, c});
        }     
        for(auto c: s) {
            vec[c - '0'].first++;
        }

        sort(vec.begin(), vec.end());
        string ans = "";
        for(auto p: vec) {
            char c = p.second;
            int n = p.first;
            for(int i = 0; i < n; i++)
                ans += c;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};