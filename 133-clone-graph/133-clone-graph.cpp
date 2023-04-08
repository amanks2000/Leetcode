/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* helper(Node* node, unordered_map<Node*, Node*>& mp) {
        if(node == NULL) return NULL;

        Node* copy = new Node(node->val);
        vector<Node*> copyNeighbours;
        mp[node] = copy;

        for(auto &it: node->neighbors) {
            if(!mp.count(it))
                copyNeighbours.push_back(helper(it, mp));
            else 
                copyNeighbours.push_back(mp[it]);
        }

        copy->neighbors = copyNeighbours;
        return copy;
    }

    Node* cloneGraph(Node* node) {
        unordered_map<Node*, Node*> mp;
        return helper(node, mp);
    }
};