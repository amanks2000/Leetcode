class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        unordered_map<int, int> map;
        int n = time.size();
        for(int i = 0; i < n; i++)
            map[time[i]%60]++;
        int count = 0;
        for(int i = 0; i < n; i++)
            cout << time[i]%60 << " ";
        for(int i = 0; i < n; i++) {
            int x = time[i] % 60;
            map[x]--;
            if(map[(60-x)%60])
                count += map[(60-x)%60];
        }
        return count;
    }
};