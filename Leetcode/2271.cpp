/* sort + sliding window + greedy, rightboundry */
class Solution {
public:
    int maximumWhiteTiles(vector<vector<int>>& tiles, int carpetLen) {
        sort(tiles.begin(), tiles.end());
        long long now = 0, ans = 0;
        for(int i = 0, j = 0; i < tiles.size(); i++) {
            while(j < tiles.size() && tiles[j][1] + 1 - tiles[i][0] <= carpetLen) {
                now += tiles[j][1] - tiles[j][0] + 1;
                j++;
            }
            if(j < tiles.size()) ans = max(ans, now + max(0, tiles[i][0] + carpetLen - tiles[j][0]));
            else ans = max(ans, now);
            now -= tiles[i][1] - tiles[i][0] + 1;
        }
        return ans;
    }
};

/* sort + sliding window + greedy, leftboundry */
class Solution {
public:
    int maximumWhiteTiles(vector<vector<int>>& tiles, int carpetLen) {
        sort(tiles.begin(), tiles.end());
        long long now = 0, ans = 0, left = 0;
        for(auto &v: tiles) {
            now += v[1] - v[0] + 1;
            while(tiles[left][1] < v[1] - carpetLen + 1) {
                now -= tiles[left][1] - tiles[left][0] + 1;
                left++;
            }
            ans = max(ans, now - max(v[1] - carpetLen + 1 - tiles[left][0], 0));
        }
        return ans;
    }
};