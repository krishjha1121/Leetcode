class Solution {
private:
    pair<int, int> findCell(int val, int n) {
        int rowTop = (val - 1) / n;
        int row = (n - 1) - rowTop;
        int col = (val - 1) % n;

        if ((n % 2 == 1 && row % 2 == 1) || (n % 2 == 0 && row % 2 == 0)) {
            col = (n - 1) - col;
        }

        return {row, col};
    }

public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        int steps = 0;

        queue<int> q;
        vector<vector<bool>> vis(n, vector<bool>(n, false));
        q.push(1);
        vis[n - 1][0] = true;

        while (!q.empty()) {
            int size = q.size();

            while (size--) {
                int x = q.front();
                q.pop();

                if (x == n * n) return steps;

                for (int k = 1; k <= 6; k++) {
                    int val = x + k;
                    if (val > n * n) continue;

                    auto [r, c] = findCell(val, n);
                    if (vis[r][c]) continue;

                    vis[r][c] = true; 

                    if (board[r][c] == -1) {
                        q.push(val);
                    } else {
                        q.push(board[r][c]);
                    }
                }
            }
            steps++;
        }

        return -1;
    }
};
