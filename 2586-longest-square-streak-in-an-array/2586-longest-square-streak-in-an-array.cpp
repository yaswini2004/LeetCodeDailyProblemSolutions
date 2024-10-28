class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        int ans = -1; // Variable to store the maximum streak length
        unordered_map<int, int> mpp; // Hash map to count occurrences 
        sort(nums.begin(), nums.end()); 
        for (int i : nums) {
            mpp[i]++;
        }
        for (int i = 0; i < nums.size(); i++) {
            long num = nums.at(i);
            int cnt = 0; // Variable to count the streak length 
            // Continue multiplying num by itself until it exceeds the largest number in nums
            while (num <= nums.at(nums.size() - 1)) {
                num *= num; 
                
                // If the squared value is not found in the map, break the streak
                if (mpp[num] == 0) {
                    if (cnt != 0) { // Update ans if a streak has been counted
                        cnt++; // Increment the streak count for the current number
                        ans = max(ans, cnt); // Update the max streak length
                    }
                    break; 
                } else {
                    cnt++; // Increment the streak count if squared value exists in the map
                }
            }
        }
        
        return ans; 
        
    }
};