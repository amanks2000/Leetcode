class Solution {
public:
    string predictPartyVictory(string s) {
        int n = s.size();
        queue<int> qr, qd;

        for(int i = 0; i < n; i++) {
            if(s[i] == 'R') qr.push(i);
            else qd.push(i);
        }

        while(true) {
            if(qr.empty()) return "Dire";
            if(qd.empty()) return "Radiant";

            int r_front = qr.front(), d_front = qd.front();
            qr.pop();
            qd.pop();
            if(r_front < d_front) qr.push(r_front + n);
            else qd.push(d_front + n);
        }
        return "";
    }
};