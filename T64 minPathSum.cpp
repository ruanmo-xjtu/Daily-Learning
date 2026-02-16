class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
            int m = grid.size(), n = grid[0].size();
            vector<vector<int>> dp(m, vector<int>(n, 0));
            for (int i = 0; i < m; ++i) {
                for (int j = 0; j < n; ++j) {
                    if (i == 0 && j == 0) continue;  // 起点不变
                    if (i == 0) {
                        grid[i][j] += grid[i][j-1];
                    } else if (j == 0) {
                        grid[i][j] += grid[i-1][j];
                    } else {
                        grid[i][j] += min(grid[i-1][j], grid[i][j-1]);
                    }
                }
            }
            return grid[m-1][n-1];
    }
};
