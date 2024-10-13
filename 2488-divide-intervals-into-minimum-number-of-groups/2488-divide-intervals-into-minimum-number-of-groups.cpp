class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<int> lefts(n), rights(n);
        for (int i = 0; i < n; i++) {
            lefts[i] = intervals[i][0];
            rights[i] = intervals[i][1];
        }
        sort(lefts.begin(), lefts.end());
        sort(rights.begin(), rights.end());
        int l = 0, r = 0, numGroups = 1, numOverlaps = 0;
        while (l < n) {
            while (l < n && lefts[l] <= rights[r]) {
                numOverlaps++;
                l++;
            }
            numGroups = max(numGroups, numOverlaps);
            if (l < n) {
                while (rights[r] < lefts[l]) {
                    numOverlaps--;
                    r++;
                }
            }
        }
        return numGroups;
        
    }
};