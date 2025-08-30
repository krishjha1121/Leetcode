class Solution {
private:
    bool solve(vector<vector<char>> &grid, int row, int erow, int col, int ecol){
        set<int> st;
        for(int i = row; i <= erow; i++){
            for(int j = col; j <= ecol; j++){
                if(grid[i][j] == '.') continue;
                if(st.count(grid[i][j] - '0')){
                    return false;
                }

                st.insert(grid[i][j] - '0');
            }
        }
        return true;
    }
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        //validate each row
        for(int i = 0; i < 9; i++){
            set<int> st;
            for(int j = 0; j < 9; j++){
                if(board[i][j] == '.') continue;
                if(st.count(board[i][j] - '0')){
                    return false;
                }
                st.insert(board[i][j] - '0');
            }
        }

        //validate each col
        for(int j = 0; j < 9; j++){
            set<int> st;
            for(int i = 0; i < 9; i++){
                if(board[i][j] == '.') continue;
                if(st.count(board[i][j] -'0')){
                    return false;
                }
                st.insert(board[i][j] - '0');
            }
        }

        //validate each 3x3 grid
        for(int i = 0; i < 9; i += 3){
            for(int j = 0; j < 9; j += 3){
                int sr = i, er = i + 2;
                int sc = j, ec = j + 2;

                if(!solve(board, sr, er, sc, ec)){
                    return false;
                }
            }
        }

        return true;
    }
};