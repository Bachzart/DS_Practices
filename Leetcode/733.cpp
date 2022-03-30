/* bfs */
class Solution {
public:
    bool isvisited[55][55] = {false};
    int X[4] = {-1, 1, 0, 0};
    int Y[4] = {0, 0, 1, -1};
    struct Node {
        int x, y;
    } node;
    bool isvalid(vector<vector<int>>& image, int x, int y, int m, int n, int value) {
        if(x < 0 || x >= m || y < 0 || y >= n) return false;
        if(isvisited[x][y]) return false;
        if(image[x][y] != value) return false;
        return true;
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        if(newColor == image[sr][sc]) return image;
        int m = image.size(), n = image[0].size(), value = image[sr][sc];
        node.x = sr, node.y = sc;
        queue<Node> q;
        q.push(node);
        isvisited[node.x][node.y] = true;
        while(!q.empty()) {
            Node tmp = q.front();
            q.pop();
            for(int i = 0; i < 4; i++) {
                int x = tmp.x + X[i];
                int y = tmp.y + Y[i];
                if(isvalid(image, x, y, m, n, value)) {
                    node.x = x;
                    node.y = y;
                    isvisited[x][y] = true;
                    image[x][y] = newColor;
                    q.push(node);
                }
            }
        }
        image[sr][sc] = newColor;
        return image;
    }
};

/* bfs, simplified version */
class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        if(newColor == image[sr][sc]) return image;
        int X[4] = {1, -1, 0, 0};
        int Y[4] = {0, 0, 1, -1};
        int m = image.size(), n = image[0].size(), value = image[sr][sc];
        queue<pair<int, int>> q;
        q.emplace(sr, sc);
        image[sr][sc] = newColor;
        while(!q.empty()) {
            int x = q.front().first, y = q.front().second;
            q.pop();
            for(int i = 0; i < 4; i++) {
                int newX = x + X[i], newY = y + Y[i];
                if(newX >= 0 && newX < m && newY >= 0 && newY < n && image[newX][newY] == value) {
                    q.emplace(newX, newY);
                    image[newX][newY] = newColor;
                }
            }
        }
        return image;
    }
};

/* dfs */
class Solution {
public:
    int X[4] = {1, -1, 0, 0};
    int Y[4] = {0, 0, 1, -1};
    void dfs(vector<vector<int>>& image, int x, int y, int color, int newColor) {
        if(image[x][y] == color) {
            image[x][y] = newColor;
            for(int i = 0; i < 4; i++) {
                int newX = x + X[i], newY = y + Y[i];
                if(newX >= 0 && newX < image.size() && newY >= 0 && newY < image[0].size()) {
                    dfs(image, newX, newY, color, newColor);
                }
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int curColor = image[sr][sc];
        if(curColor != newColor) dfs(image, sr, sc, curColor, newColor);
        return image;
    }
};