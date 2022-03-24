/* method 1: use for loop to reduce code */
class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        int m = img.size(), n = img[0].size();
        vector<vector<int>> ret = img;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                int num = 0, sum = 0;
                for(int x = i - 1; x <= i + 1; x++) {
                    for(int y = j - 1; y <= j + 1; y++) {
                        if(x >= 0 && x < m && y >= 0 && y < n) {
                            sum += img[x][y];
                            num++;
                        }
                    }
                }
                ret[i][j] = sum / num;
            }
        }
        return ret;
    }
};


/* method 2: simulate the process, but this is not a smart mehtod. */
class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        vector<vector<int>> ret = img;
        int r = img.size(), c = img[0].size();
        if(r == 1 && c == 1) {
            ret[0][0] = img[0][0];
        } else if(r == 1 && c != 1) {
            for(int i = 0; i < c; i++) {
                if(i == 0) {
                    ret[0][i] = (img[0][i] + img[0][i + 1]) / 2;
                } else if(i == c - 1) {
                    ret[0][i] = (img[0][i] + img[0][i - 1]) / 2;
                } else {
                    ret[0][i] = (img[0][i] + img[0][i + 1] + img[0][i - 1]) / 3;
                }
            }
        } else if(r != 1 && c == 1) {
            for(int i = 0; i < r; i++) {
                if(i == 0) {
                    ret[i][0] = (img[i][0] + img[i + 1][0]) / 2;
                } else if(i == c - 1) {
                    ret[i][0] = (img[i][0] + img[i - 1][0]) / 2;
                } else {
                    ret[i][0] = (img[i][0] + img[i + 1][0] + img[i - 1][0]) / 3;
                }
            }
        } else {
            for(int i = 0; i < r; i++) {
                for(int j = 0; j < c; j++) {
                    if(i == 0 && j == 0) {
                        ret[i][j] = (img[i][j] + img[i][j + 1] + img[i + 1][j] + img[i + 1][j + 1]) / 4;
                    } else if(i == 0 && j == c - 1){
                        ret[i][j] = (img[i][j] + img[i][j - 1] + img[i + 1][j] + img[i + 1][j - 1]) / 4;
                    } else if(i == r - 1 && j == 0) {
                        ret[i][j] = (img[i][j] + img[i - 1][j] + img[i - 1][j + 1] + img[i][j + 1]) / 4;
                    } else if(i == r - 1 && j == c - 1) {
                        ret[i][j] = (img[i][j] + img[i - 1][j - 1] + img[i][j - 1] + img[i - 1][j]) / 4;
                    } else if(i == 0 && j != 0 && j != c - 1) {
                        ret[i][j] = (img[i][j] + img[i][j - 1] + img[i][j + 1] + img[i + 1][j] + img[i + 1][j - 1] + img[i + 1][j + 1]) / 6;
                    } else if(i != 0 && i != r - 1 && j == 0) {
                        ret[i][j] = (img[i][j] + img[i - 1][j] + img[i + 1][j] + img[i - 1][j + 1] + img[i][j + 1] + img[i + 1][j + 1]) / 6;
                    } else if(i == r - 1 && j != 0 && j != c - 1) {
                        ret[i][j] = (img[i][j] + img[i][j - 1] + img[i][j + 1] + img[i - 1][j] + img[i - 1][j - 1] + img[i - 1][j + 1]) / 6;
                    } else if(i != 0 && i != r - 1 && j == c - 1) {
                        ret[i][j] = (img[i][j] + img[i - 1][j] + img[i + 1][j] + img[i][j - 1] + img[i - 1][j - 1] + img[i + 1][j - 1]) / 6;
                    } else {
                        ret[i][j] = (img[i][j] + img[i - 1][j - 1] + img[i - 1][j] + img[i - 1][j + 1] + img[i][j - 1] + img[i][j + 1] + img[i + 1][j - 1] + img[i + 1][j] + img[i + 1][j + 1]) / 9;
                    }
                }
            }
        } 
    return ret;
    }
};