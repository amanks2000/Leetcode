class Solution {
public:
    string simplifyPath(string path) {
        int n = path.size(), i = 0;
        stack<string> s;
        while(i < n) {
            // cout << path[i] << " ";
            if(path[i] == '/'){
                if(s.empty() || (!s.empty() && s.top() != "/")) s.push("/");
                i++;
                continue;
            }
            else if(path[i] == '.') {
                if(i+1 < n && path[i+1] == '.' && (i+2 == n || path[i+2] == '/')) {
                    i+=2;
                    if(!s.empty()) s.pop();
                    if(!s.empty()) s.pop();
                }
                else if(i+1 == n || path[i+1] == '/') {
                    if(!s.empty()) s.pop();
                    i++;
                }
                else {
                    string temp = "";
                    while (i < n && path[i] != '/') {
                        temp += path[i];
                        i++;
                    }
                    // cout << temp << " ";
                    s.push(temp);
                }
               
                continue;
            }
            else {
                string temp = "";
                while(i < n && path[i] != '/') {
                    temp += path[i];
                    i++;
                }
                s.push(temp);
            }         
        }
        if(!s.empty() && s.top() == "/") s.pop();
        if(s.empty()) return "/";

        string ans = "";
        while(!s.empty()) {
            ans = s.top() + ans;
            s.pop();
        }
        return ans;
    }
};