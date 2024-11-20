class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
         long long maxsum=0,sum=0; int n=nums.size(),i=0;
        unordered_set<int> ele;
        for(int j=0;j<n;j++){
            sum+=nums[j];
            if(ele.find(nums[j])!=ele.end()){
                while(nums[i]!=nums[j]){ ele.erase(nums[i]); sum-=nums[i]; i++; }
                sum-=nums[i];
                i++;
            }
            ele.insert(nums[j]);
            if(j-i+1==k){
                //cout<<i<<" "<<j<<" "<<sum<<endl;
                maxsum=max(maxsum,sum);
                sum-=nums[i]; ele.erase(nums[i]); i++;
            }
        }
        return maxsum;
        
    }
};