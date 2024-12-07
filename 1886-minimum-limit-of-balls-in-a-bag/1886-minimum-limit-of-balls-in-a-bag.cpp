class Solution {
public:
    int minimumSize(vector<int>& nums, int maxOperations) {
        int left = 1, right = *max_element(begin(nums), end(nums));
        int ans = right, mid;

        while(left <= right){
            mid = left + (right - left)/2;

            if(isPossible(mid, nums, maxOperations)){
                ans = mid;
                right = mid - 1;
            }
            else{
                left = mid + 1;
            }
        }

        return ans;
    }

private:
    bool isPossible(int balls, vector<int>& nums, int maxOperations){
        int count = 0;
        for(int &num: nums){
            if(num <= balls) continue;

            count += (num/balls - 1 + (num%balls != 0));
        }

        return count <= maxOperations;
    }
};