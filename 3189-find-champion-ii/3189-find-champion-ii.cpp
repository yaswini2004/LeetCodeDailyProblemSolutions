class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        unordered_set<int> source_set;

        // Add all sources to the source set
        for (int i = 0; i < n; i++) {
            source_set.insert(i);
        }

        // Remove all the destinations from the source set
        for (vector<int>& edge : edges) {
            source_set.erase(edge[1]);
        }

        if (source_set.size() == 1) {
            return *source_set.begin();
        } else {
            return -1;
        }
        
    }
};