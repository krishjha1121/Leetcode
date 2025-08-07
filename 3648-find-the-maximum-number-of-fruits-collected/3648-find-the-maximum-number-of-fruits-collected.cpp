class Solution {
private:
    int countChild1(vector<vector<int>>& grid, int n) {
        int res = 0;
        for (int i = 0; i < n; ++i) {
            res += grid[i][i]; // main diagonal
        }
        return res;
    }

    // Memoized DP for Child2
    int countChild2(vector<vector<int>>& grid, int n, int i, int j, vector<vector<int>>& dp2) {
        if (i >= n || j >= n || i < 0 || j < 0 || i >= j) return 0;
        if (dp2[i][j] != -1) return dp2[i][j];

        int diag = grid[i][j] + countChild2(grid, n, i + 1, j + 1, dp2);
        int left = grid[i][j] + countChild2(grid, n, i + 1, j - 1, dp2);
        int down = grid[i][j] + countChild2(grid, n, i + 1, j, dp2);

        return dp2[i][j] = max({diag, left, down});
    }

    // Memoized DP for Child3
    int countChild3(vector<vector<int>>& grid, int n, int i, int j, vector<vector<int>>& dp3) {
        if (i >= n || j >= n || i < 0 || j < 0 || i <= j) return 0;
        if (dp3[i][j] != -1) return dp3[i][j];

        int diag = grid[i][j] + countChild3(grid, n, i - 1, j + 1, dp3);
        int right = grid[i][j] + countChild3(grid, n, i, j + 1, dp3);
        int up = grid[i][j] + countChild3(grid, n, i + 1, j + 1, dp3);

        return dp3[i][j] = max({diag, right, up});
    }

public:
    int maxCollectedFruits(vector<vector<int>>& fruits) {
        int n = fruits.size();

        vector<vector<int>> dp2(n, vector<int>(n, -1)); // memo table for Child2
        vector<vector<int>> dp3(n, vector<int>(n, -1)); // memo table for Child3

        int child1 = countChild1(fruits, n);
        int child2 = countChild2(fruits, n, 0, n - 1, dp2);
        int child3 = countChild3(fruits, n, n - 1, 0, dp3);

        return child1 + child2 + child3;
    }
};
