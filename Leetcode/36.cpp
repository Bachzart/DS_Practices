/* method 1 */
class Solution {
public:
    bool isvalid(vector<vector<char>>& board, int r, int c) {
        for(int i = 0; i < 9; i++) {
            if(i != c && board[r][i] == board[r][c]) return false;
        }
        for(int i = 0; i < 9; i++) {
            if(i != r && board[i][c] == board[r][c]) return false;
        }
        int R = r >= 3 ? r >= 6 ? 9 : 6 : 3;
        int C = c >= 3 ? c >= 6 ? 9 : 6 : 3;
        for(int i = R - 3; i < R; i++) {
            for(int j = C - 3; j < C; j++) {
                if(i != r && j != c && isdigit(board[i][j]) && board[i][j] == board[r][c]) return false;
            }
        }
        return true;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i = 0; i < 9; i++) {
            for(int j = 0; j < 9; j++) {
                if(isdigit(board[i][j]) && !isvalid(board, i, j)) return false;
            }
        }
        return true;
    }
};

/* method 2 */
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int rows[9][9] = {0};
        int columns[9][9] = {0};
        int submatrix[3][3][9] = {0};
        for(int i = 0; i < 9; i++) {
            for(int j = 0; j < 9; j++) {
                char c = board[i][j];
                if(c != '.') {
                    int index = c - '0' - 1;
                    rows[i][index]++;
                    columns[j][index]++;
                    submatrix[i / 3][j / 3][index]++;
                    if(rows[i][index] > 1 || columns[j][index] > 1 || submatrix[i / 3][j / 3][index] > 1) {
                        return false;
                    }
                }
            }
        }
        return true;
    }
};