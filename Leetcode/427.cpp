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
    Node* construct(vector<vector<int>>& grid) {
        function<Node*(int, int, int, int)> dfs = [&](int r0, int c0, int r1, int c1) {
            for(int i = r0; i < r1; i++) {
                for(int j = c0; j < c1; j++) {
                    if(grid[i][j] != grid[r0][c0]) {
                        return new Node(
                            true,
                            false,
                            dfs(r0, c0, (r0 + r1) / 2, (c0 + c1) / 2),
                            dfs(r0, (c0 + c1) / 2, (r0 + r1) / 2, c1),
                            dfs((r0 + r1) / 2, c0, r1, (c0 + c1) / 2),
                            dfs((r0 + r1) / 2, (c0 + c1) / 2, r1, c1)
                        );
                    }
                }
            }
            return new Node(grid[r0][c0], true);
        };
        return dfs(0, 0, grid.size(), grid.size());
    }
};

class Solution {
public:
    Node* buildquadtree(int rs, int cs, int re, int ce, vector<vector<int>>& grid) {
        for(int i = rs; i < re; i++) {
            for(int j = cs; j < ce; j++) {
                if(grid[i][j] != grid[rs][cs]) {
                    return new Node(
                        true,
                        false,
                        buildquadtree(rs, cs, (rs + re) / 2, (cs + ce) / 2, grid),
                        buildquadtree(rs, (cs + ce) / 2, (rs + re) / 2, ce, grid),
                        buildquadtree((rs + re) / 2, cs, re, (cs + ce) / 2, grid),
                        buildquadtree((rs + re) / 2, (cs + ce) / 2, re, ce, grid)
                    );
                }
            }
        }
        return new Node(grid[rs][cs], true);
    }
    Node* construct(vector<vector<int>>& grid) {
        int n = grid.size();
        if(n == 1) return new Node(grid[0][0], true);
        return buildquadtree(0, 0, n, n, grid);
    }
};

class Solution {
public:
    Node* buildquadtree(int rs, int cs, int re, int ce, vector<vector<int>>& grid) {
        for(int i = rs; i < re; i++) {
            for(int j = cs; j < ce; j++) {
                if(grid[i][j] != grid[rs][cs]) {
                    Node* node = new Node;
                    node->val = 0;
                    node->isLeaf = false;
                    node->topLeft = buildquadtree(rs, cs, (rs + re) / 2, (cs + ce) / 2, grid);
                    node->topRight = buildquadtree(rs, (cs + ce) / 2, (rs + re) / 2, ce, grid);
                    node->bottomLeft = buildquadtree((rs + re) / 2, cs, re, (cs + ce) / 2, grid);
                    node->bottomRight = buildquadtree((rs + re) / 2, (cs + ce) / 2, re, ce, grid);
                    return node;
                }
            }
        }
        return new Node(grid[rs][cs], true);
    }
    Node* construct(vector<vector<int>>& grid) {
        int n = grid.size();
        if(n == 1) return new Node(grid[0][0], true);
        return buildquadtree(0, 0, n, n, grid);
    }
};

class Solution {
public:
    int getprefixsum(int rs, int cs, int re, int ce, vector<vector<int>>& pre) {
        return pre[re][ce] - pre[re][cs] - pre[rs][ce] + pre[rs][cs];
    }
    Node* buildquadtree(int rs, int cs, int re, int ce, vector<vector<int>>& pre) {
        int prefixsum = getprefixsum(rs, cs, re, ce, pre);
        if(prefixsum == 0) return new Node(0, true);
        if(prefixsum == (re - rs) * (ce - cs)) return new Node(1, true);
        return new Node(
            true,
            false,
            buildquadtree(rs, cs, (rs + re) / 2, (cs + ce) / 2, pre),
            buildquadtree(rs, (cs + ce) / 2, (rs + re) / 2, ce, pre),
            buildquadtree((rs + re) / 2, cs, re, (cs + ce) / 2, pre),
            buildquadtree((rs + re) / 2, (cs + ce) / 2, re, ce, pre)
        );
    }
    Node* construct(vector<vector<int>>& grid) {
        int n = grid.size();
        if(n == 1) return new Node(grid[0][0], true);
        vector<vector<int>> pre(n + 1, vector<int>(n + 1));
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                pre[i][j] = pre[i - 1][j] + pre[i][j - 1] - pre[i - 1][j - 1] + grid[i - 1][j - 1];
            }
        }
        return buildquadtree(0, 0, n, n, pre);
    }
};