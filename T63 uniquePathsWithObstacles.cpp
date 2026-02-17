class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if (obstacleGrid.empty() || obstacleGrid[0].empty()) {
            return 0;
        }
        
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();  
        vector<int> f(m, 0); 

        f[0] = (obstacleGrid[0][0] == 0);
        
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (obstacleGrid[i][j] == 1) {
                    f[j] = 0;
                } else {
                    if (j > 0) {
                        f[j] += f[j - 1];
                    }
                }
            }
        }
        return f[m - 1]; 
    }
};
