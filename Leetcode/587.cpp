class Solution {
public:
    int cross(vector<int>& p, vector<int>& q, vector<int>& r) {
        return (q[0] - p[0]) * (r[1] - q[1]) - (q[1] - p[1]) * (r[0] - q[0]);
    }
    vector<vector<int>> outerTrees(vector<vector<int>>& trees) {
        int n = trees.size();
        if(n < 4) return trees;
        int leftmost = 0;
        for(int i = 0; i < n; i++) {
            if(trees[i][0] < trees[leftmost][0] ||
                (trees[i][0] == trees[leftmost][0] && trees[i][1] < trees[leftmost][1])) leftmost = i;
        }
        vector<vector<int>> res;
        vector<bool> visit(n, false);
        int p = leftmost;
        do{
            int q = (p + 1) % n;
            for(int r = 0; r < n; r++) {
                if(cross(trees[p], trees[q], trees[r]) < 0) q = r;
            }
            for(int i = 0; i < n; i++) {
                if(visit[i] || i == p || i == q) continue;
                if(cross(trees[p], trees[q], trees[i]) == 0) {
                    res.push_back(trees[i]);
                    visit[i] = true;
                }
            }
            if(!visit[q]) {
                res.push_back(trees[q]);
                visit[q] = true;
            }
            p = q;
        } while(p != leftmost);
        return res;
    }
};