class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>> matrix(m, vector<int>(n));
        int size = guards.size();
        for(int i = 0; i < walls.size(); i++) {
            matrix[walls[i][0]][walls[i][1]] = 2;
        }
        for(int i = 0; i < size; i++) {
            int x = guards[i][0], y = guards[i][1], tmpx, tmpy;
            matrix[x][y] = 3;
            // up
            tmpx = x - 1, tmpy = y;
            while(tmpx >= 0) {
                if(matrix[tmpx][tmpy] == 2) break;
                matrix[tmpx][tmpy] = 1;
                tmpx--;
            }
            // down
            tmpx = x + 1, tmpy = y;
            while(tmpx < m) {
                if(matrix[tmpx][tmpy] == 2) break;
                matrix[tmpx][tmpy] = 1;
                tmpx++;
            }
            // left
            tmpx = x, tmpy = y - 1;
            while(tmpy >= 0) {
                if(matrix[tmpx][tmpy] == 2) break;
                matrix[tmpx][tmpy] = 1;
                tmpy--;
            }
            // right
            tmpx = x, tmpy = y + 1;
            while(tmpy < n) {
                if(matrix[tmpx][tmpy] == 2) break;
                matrix[tmpx][tmpy] = 1;
                tmpy++;
            }
        }
        int cnt = 0;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(matrix[i][j] == 0) cnt++;
            }
        }
        return cnt;
    }
};

class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>> matrix(m, vector<int>(n));
        int size = guards.size(), cnt = walls.size();
        for(int i = 0; i < cnt; i++) {
            matrix[walls[i][0]][walls[i][1]] = 2;
        }
        for(int i = 0; i < size; i++) {
            matrix[guards[i][0]][guards[i][1]] = 3;
        }
        cnt += size;
        for(int i = 0; i < size; i++) {
            int x = guards[i][0], y = guards[i][1], tmpx, tmpy;
            matrix[x][y] = 3;
            // up
            tmpx = x - 1, tmpy = y;
            while(tmpx >= 0) {
                if(matrix[tmpx][tmpy] == 2) break;
                else if(matrix[tmpx][tmpy] == 0) {
                    matrix[tmpx][tmpy] = 1;
                    cnt++;
                }
                tmpx--;
            }
            // down
            tmpx = x + 1, tmpy = y;
            while(tmpx < m) {
                if(matrix[tmpx][tmpy] == 2) break;
                else if(matrix[tmpx][tmpy] == 0) {
                    matrix[tmpx][tmpy] = 1;
                    cnt++;
                }
                tmpx++;
            }
            // left
            tmpx = x, tmpy = y - 1;
            while(tmpy >= 0) {
                if(matrix[tmpx][tmpy] == 2) break;
                else if(matrix[tmpx][tmpy] == 0) {
                    matrix[tmpx][tmpy] = 1;
                    cnt++;
                }
                tmpy--;
            }
            // right
            tmpx = x, tmpy = y + 1;
            while(tmpy < n) {
                if(matrix[tmpx][tmpy] == 2) break;
                else if(matrix[tmpx][tmpy] == 0) {
                    matrix[tmpx][tmpy] = 1;
                    cnt++;
                }
                tmpy++;
            }
        }
        return m * n - cnt;
    }
};

class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>> matrix(m, vector<int>(n));
        int size = guards.size(), cnt = walls.size();
        for(int i = 0; i < cnt; i++) {
            matrix[walls[i][0]][walls[i][1]] = 2;
        }
        for(int i = 0; i < size; i++) {
            matrix[guards[i][0]][guards[i][1]] = 3;
        }
        cnt += size;
        for(int i = 0; i < size; i++) {
            int x = guards[i][0], y = guards[i][1], tmpx, tmpy;
            matrix[x][y] = 3;
            // up
            tmpx = x - 1, tmpy = y;
            while(tmpx >= 0) {
                if(matrix[tmpx][tmpy] == 0) {
                    matrix[tmpx][tmpy] = 1;
                    cnt++;
                } else if(matrix[tmpx][tmpy] != 1) break;
                tmpx--;
            }
            // down
            tmpx = x + 1, tmpy = y;
            while(tmpx < m) {
                if(matrix[tmpx][tmpy] == 0) {
                    matrix[tmpx][tmpy] = 1;
                    cnt++;
                } else if(matrix[tmpx][tmpy] != 1) break;
                tmpx++;
            }
            // left
            tmpx = x, tmpy = y - 1;
            while(tmpy >= 0) {
                if(matrix[tmpx][tmpy] == 0) {
                    matrix[tmpx][tmpy] = 1;
                    cnt++;
                } else if(matrix[tmpx][tmpy] != 1) break;
                tmpy--;
            }
            // right
            tmpx = x, tmpy = y + 1;
            while(tmpy < n) {
                if(matrix[tmpx][tmpy] == 0) {
                    matrix[tmpx][tmpy] = 1;
                    cnt++;
                } else if(matrix[tmpx][tmpy] != 1) break;
                tmpy++;
            }
        }
        return m * n - cnt;
    }
};

class Solution {
public:
    int X[4] = {1, -1, 0, 0};
    int Y[4] = {0, 0, 1, -1};
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>> matrix(m, vector<int>(n));
        int size = guards.size(), cnt = walls.size();
        for(int i = 0; i < cnt; i++) {
            matrix[walls[i][0]][walls[i][1]] = 2;
        }
        for(int i = 0; i < size; i++) {
            matrix[guards[i][0]][guards[i][1]] = 3;
        }
        cnt += size;
        for(int i = 0; i < size; i++) {
            int x = guards[i][0], y = guards[i][1], tmpx, tmpy;
            for(int j = 0; j < 4; j++) {
                int newx = x + X[j], newy = y + Y[j];
                while(newx >= 0 && newx < m && newy >= 0 && newy < n) {
                    if(matrix[newx][newy] == 0) {
                        matrix[newx][newy] = 1;
                        cnt++;
                    } else if(matrix[newx][newy] != 1) break;
                    newx += X[j];
                    newy += Y[j];
                }
            }
        }
        return m * n - cnt;
    }
};