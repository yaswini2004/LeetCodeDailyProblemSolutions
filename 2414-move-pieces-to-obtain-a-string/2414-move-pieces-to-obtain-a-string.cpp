class Solution {
public:
    bool canChange(string start, string target) {
        int n = start.size();
        if (n != target.size()) return false;
        int need_right = 0, need_left = 0;
        for (int i = 0; i < n; ++i) {
            if (target[i] == 'L') {
                if (need_right) return false;
                ++need_left;
            }
            if (start[i] == 'R') {
                if (need_left) return false;
                ++need_right;
            }
            if (target[i] == 'R') {
                if (!need_right) return false;
                --need_right;
            }
            if (start[i] == 'L') {
                if (!need_left) return false;
                --need_left;
            }
        }
        return !(need_left || need_right);
    }
};