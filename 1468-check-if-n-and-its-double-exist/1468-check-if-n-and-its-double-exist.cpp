class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        for (auto it = arr.begin(); it != arr.end(); it++) {
            int target = *it * 2;
            auto findIt = lower_bound(arr.begin(), arr.end(), target);
            if (findIt != arr.end() && *findIt == target && findIt != it) {
                return true;
            }
        }
        return false;
        
    }
};