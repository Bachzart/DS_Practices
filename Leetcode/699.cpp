/* violent solution */
class Solution {
public:
    vector<int> fallingSquares(vector<vector<int>>& positions) {
        int size = positions.size();
        vector<int> ans(size);
        for(int i = 0; i < size; i++) {
            int left1 = positions[i][0], right1 = positions[i][0] + positions[i][1] - 1;
            ans[i] = positions[i][1];
            for(int j = 0; j < i; j++) {
                int left2 = positions[j][0], right2 = positions[j][0] + positions[j][1] - 1;
                if(!(right1 < left2 || left1 > right2)) {
                // if(left2 <= right1 && right2 >= left1) {
                    ans[i] = max(ans[i], ans[j] + positions[i][1]);
                }
            }
        }
        for(int i = 1; i < size; i++) {
            ans[i] = max(ans[i], ans[i - 1]);
        }
        return ans;
    }
};


/* ordered set */

class Solution {
public:
    vector<int> fallingSquares(vector<vector<int>>& positions) {
        int size = positions.size();
        vector<int> ans(size);
        map<int, int> heightmap;
        heightmap[0] = 0;
        for(int i = 0; i < size; i++) {
            int size = positions[i][1];
            int left = positions[i][0], right = positions[i][0] + positions[i][1] - 1;
            auto lp = heightmap.upper_bound(left), rp = heightmap.upper_bound(right);
            int rheight = prev(rp)->second;
            int height = 0;
            for(auto p = prev(lp); p != rp; p++) {
                height = max(height, p->second + size);
            }
            heightmap.erase(lp, rp);
            heightmap[left] = height;
            if(rp == heightmap.end() || rp->first != right + 1) {
                heightmap[right + 1] = rheight;
            }
            ans[i] = i > 0 ? max(ans[i - 1], height) : height;
        }
        return ans;
    }
};