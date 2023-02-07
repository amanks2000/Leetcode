class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size(), j = 0, prev = -1, i = 0, last_f = -1, last_s = -1;
        int first = -1, count_first = 0, second = -1, count_second = 0, res = 0;

        while(j < n) {
            if(first == -1 || fruits[j] == first) {
                first = fruits[j];
                count_first++;
                last_f = j;;
            }
            else if(second == -1 || fruits[j] == second) {
                second = fruits[j];
                count_second++;
                last_s = j;
            }
            else {
                res = max(res, count_first + count_second);
                if(prev == first) {
                    swap(first, second);
                    swap(count_first, count_second);
                    swap(last_f, last_s);
                }
                
                while(i <= last_f) {
                    if(fruits[i] == second) count_second--;
                    i++;
                }

                first = second;
                count_first = count_second;
                last_f = last_s;
                second = fruits[j];
                count_second = 1;
                last_s = j;
            }
            prev = fruits[j];
            j++;
        }
        
        res = max(res, count_first + count_second);
        return res;
    }
};