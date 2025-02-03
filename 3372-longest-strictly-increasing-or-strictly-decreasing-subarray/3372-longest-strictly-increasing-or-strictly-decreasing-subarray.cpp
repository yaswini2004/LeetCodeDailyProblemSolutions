class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int inc=1,dec=1;
        int maxlen=0;
        if(nums.size()==1){
            return 1;
        }
        for(int i =0;i<nums.size()-1;i++){
            if(nums[i+1]>nums[i]){
                inc++;
                dec=1;
            } else if(nums[i+1]<nums[i]){
                inc=1;
                dec++;
            }else{
                inc=dec=1;
            }
        maxlen=max({maxlen,inc,dec});
        }
        return maxlen;   
    }
};