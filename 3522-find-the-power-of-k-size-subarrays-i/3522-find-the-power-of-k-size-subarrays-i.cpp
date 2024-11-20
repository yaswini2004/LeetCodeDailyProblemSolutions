class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        if(k == 1) return nums;
        int n = nums.size();
        
        vector<int> pre(n, 0);
        pre[0] = 1;
        for(int i=1; i<n; i++){
            if(nums[i] == nums[i-1] + 1){
                pre[i] = pre[i-1] + 1;
            } else {
                pre[i] = pre[i-1];
            }
        }
        
        vector<int> ans(n-k+1, -1);
        for(int i=0; i<n-k+1; i++){
            if(pre[i+k-1] - pre[i] == k - 1){
                ans[i] = nums[i+k-1];
            }
        }
        
        return ans;
        
    }
};