class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        for (vector<char>& row : box) {
            // Move things rightwards until it reaches a blocker.
            // The blocker position is initialised to past the end of the row.
            int blocker = row.size();
            for (int i = row.size() - 1; i >= 0; i--) {
                // If rock, process shift first.
                if (row[i] == '#') {
                    // Take tmp, because we clear the current pos first. This is for when the 
                    // current rock stays in the same position.
                    char tmp = row[i];
                    // Clear the space that the current thig took in the grid.
                    row[i] = '.';
                    // Move the current thing to the position rightwards, to the left adjacent of the last blocker.
                    row[blocker - 1] = tmp;
                    
                    // Move the blocker left.
                    blocker--;
                }
                
                // If the current psoition we are looking at is a wall, then update the blocker to that.
                if (row[i] == '*') {
                    blocker = i;
                }
            }
        }

        // Construct result box.
        vector<vector<char>> res(box[0].size(), vector<char>(box.size(), '.'));

        // Iterate through the vertical box and map that to the rotated box.
        for (int i = 0; i < box.size(); i++) {
            for (int j = 0; j < box[0].size(); j++) {
                res[j][(box.size() - 1) - i] = box[i][j];
            }
        }

        return res;
        
        
    }
};