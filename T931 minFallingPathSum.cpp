class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size(), f[n + 2];
        f[0] = f[n + 1] = INT_MAX;
        for (int i = 0; i < n; i++)
            f[i + 1] = matrix[0][i];
        for (int r = 1; r < n; r++) {
            int pre = f[0];
            for (int c = 0; c < n; c++) {
                int tmp = pre;
                pre = f[c + 1];
                f[c + 1] = min(tmp, min(f[c + 1], f[c + 2])) + matrix[r][c];
            }
        }
        return *min_element(f + 1, f + 1 + n);
    }
};
