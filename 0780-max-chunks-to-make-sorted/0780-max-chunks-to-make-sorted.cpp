class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int chunk_count = 0;
        int max_val = 0;
        for (int i = 0; i < arr.size(); i++) {
            // Update the max chunk value
            max_val = max(max_val, arr[i]);

            if (max_val == i) {
                chunk_count++;
            }
        }

        return chunk_count;
        
    }
};