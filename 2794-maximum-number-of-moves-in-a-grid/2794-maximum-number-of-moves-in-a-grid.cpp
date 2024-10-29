class Solution {
public:
    int maxMoves(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<int> prev(m, 0);
        int res = 0, aliveCount = m;
        for (int j = 1; j < n && aliveCount > 0; j++) {
            vector<int> curr(m, -1); // -1 as cell unreachable
            aliveCount = 0;
            for (int i = 0; i < m; i++) {
                if (i > 0 && grid[i][j] > grid[i - 1][j - 1] && prev[i - 1] != -1) { 
                    curr[i] = max(curr[i], prev[i - 1] + 1);
                }
                if (grid[i][j] > grid[i][j - 1] && prev[i] != -1) {
                    curr[i] = max(curr[i], prev[i] + 1);
                }
                if (i < m - 1 && grid[i][j] > grid[i + 1][j - 1] && prev[i + 1] != -1) {
                    curr[i] = max(curr[i], prev[i + 1] + 1);
                }
                if (curr[i] != -1) aliveCount++;
                res = max(res, curr[i]);
            }
            prev = curr;
        }
        return res;
        
    }
};