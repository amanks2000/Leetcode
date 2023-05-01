class Solution {
public:
    double average(vector<int>& salary) {
        double sum = 0, n = salary.size();
        for(auto it: salary) sum += it;

        sum -= *max_element(salary.begin(), salary.end());
        sum -= *min_element(salary.begin(), salary.end());
        sum = sum / (n - 2);

        return sum;
    }
};