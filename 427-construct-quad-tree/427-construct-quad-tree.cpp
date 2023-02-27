/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
public:
    Node* helper(int si, int sj, int ei, int ej, vector<vector<int>>& grid) {
        int flag = 0, prev = grid[si][sj];

        for(int i = si; i <= ei; i++) {
            for(int j = sj; j <= ej; j++) {
                if(grid[i][j] != prev) {
                    flag = 1;
                    break;
                }
            }
        }

        if(flag) {
            Node* newNode = new Node(1, 0);
            newNode->topLeft = helper(si, sj, (ei + si)/2, (ej + sj)/2, grid);
            newNode->topRight = helper(si,(ej + sj)/2 + 1, (ei + si)/2, ej, grid);
            newNode->bottomLeft = helper((ei + si)/2 + 1, sj, ei, (ej + sj)/2, grid);
            newNode->bottomRight = helper((ei + si)/2 + 1, (ej + sj)/2 + 1,ei, ej, grid);
            return newNode;
        }
        else {
            int val = grid[si][sj];
            Node* newNode = new Node(val, 1);
            return newNode;
        }
    }

    Node* construct(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        return helper(0, 0, m-1, n-1, grid);
    }
};