class DisjointSet
{
public:
    vector<int> size, parent;

    DisjointSet(int n)
    {
        size.resize(n + 1, 1);
        parent.resize(n + 1);
        for (int i = 0; i <= n; i++)
            parent[i] = i;
    }

    int findUParent(int node)
    {
        if (node == parent[node])
            return node;

        // Path Compression
        return parent[node] = findUParent(parent[node]);
    }

    void unionBySize(int u, int v)
    {
        int pu = findUParent(u);
        int pv = findUParent(v);
        if (pu == pv)
            return;

        if (size[pu] < size[pv])
        {
            size[pv] += size[pu];
            parent[pu] = pv;
        }
        else
        {
            size[pu] += size[pv];
            parent[pv] = pu;
        }
    }
};

class Solution {
public:
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        DisjointSet ds(row*col + 2);
        vector<vector<int>> grid(row, vector<int>(col, 1));

        int start = row*col + 1, end = row*col + 2;
        for(int j = 0; j < col; j++) {
            ds.unionBySize(j, start); // unify first row with a dummy node
            ds.unionBySize((row-1)*col + j, end); // unify last row with another dummy node
        }

        vector<int> delRow = {-1, 0, +1, 0};
        vector<int> delCol = {0, -1, 0, +1};

        // assuming all nodes are 1 initially (opposite way)
        for(int i = row*col - 1; i >= 0; i--) {
            int nr = cells[i][0] - 1, nc = cells[i][1] - 1;
            grid[nr][nc] = 0;
            int node = nr*col + nc;
            
            for(int k = 0; k < 4; k++) {
                int r = nr + delRow[k], c = nc + delCol[k];
                if(r < 0 || r >= row || c < 0 || c >= col || grid[r][c])
                    continue;

                int child = r*col + c;
                ds.unionBySize(node, child);

                if(ds.findUParent(start) == ds.findUParent(end))
                    return i;
            }
        }
        return -1;
    }
};