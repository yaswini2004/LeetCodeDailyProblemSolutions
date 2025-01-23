class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
         vector<int> rowCounts(size(grid), 0), colCounts(size(grid[0]), 0);

        // Count servers in each row and each column
        for (int row = 0; row < size(grid); ++row)
            for (int col = 0; col < size(grid[0]); ++col)
                if (grid[row][col]) {
                    rowCounts[row]++;
                    colCounts[col]++;
                }

        int communicableServersCount = 0;

        // Count servers that can communicate (in the same row or column)
        for (int row = 0; row < size(grid); ++row)
            for (int col = 0; col < size(grid[0]); ++col)
                if (grid[row][col])
                    communicableServersCount +=
                        rowCounts[row] > 1 || colCounts[col] > 1;

        return communicableServersCount;
        
    }
};