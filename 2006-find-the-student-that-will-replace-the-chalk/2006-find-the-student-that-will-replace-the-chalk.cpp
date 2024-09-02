class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        long totalc=0;
        for(int i=0;i<chalk.size();i++){
            totalc+=chalk[i];
            
        }
        k = k%totalc;
        int ans=0;
        for(int i=0;i<chalk.size();i++){
            if(chalk[i]>k){
                return i;
            }
            k=k-chalk[i];

        }
        return 0;
    }
};