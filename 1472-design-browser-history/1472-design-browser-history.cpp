class BrowserHistory {
public:
    stack<string> s;
    queue<string> q;
    string cur = "";
    unordered_map<string, int> mp;

    BrowserHistory(string homepage) {
        s.push(homepage);
        q.push(homepage);
        cur = homepage;
        mp[homepage]++;
    }
    
    void visit(string url) {
        while(s.top() != cur) {
            mp[s.top()]--;
            s.pop();
        }

        if(mp[url]) {
            mp[url]++;
            url += (mp[url] + '0');
        }
        s.push(url);
        
        queue<string> temp;
        while(q.front() != cur) {
            temp.push(q.front());
            q.pop();
        }
        temp.push(cur);
        temp.push(url);
        q = temp;
        
        cur = url;
    }
    
    string back(int steps) {
        stack<string> temp = s;
        while(s.top() != cur) s.pop();

        while(s.size() > 1 && steps--) 
            s.pop();

        swap(temp, s);
        string ans = temp.top();
        cur = ans;
        
        if(ans[ans.size() - 1] >= '0' && ans[ans.size() - 1] <= '9') {
            ans = ans.substr(0, ans.size() - 1);
        }
        return ans;
    }
    
    string forward(int steps) {
        queue<string> temp = q;
        while(q.front() != cur) q.pop();

        while(q.size() > 1 && steps--) 
            q.pop();

        swap(temp, q);
        string ans = temp.front();
        cur = ans;
        
        if(ans[ans.size() - 1] >= '0' && ans[ans.size() - 1] <= '9') {
            ans = ans.substr(0, ans.size() - 1);
        }
        return ans;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */