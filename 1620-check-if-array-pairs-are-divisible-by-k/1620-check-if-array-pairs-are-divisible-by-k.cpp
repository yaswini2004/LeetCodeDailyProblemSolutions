class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        int freq[k];
        memset(freq,0,sizeof(freq));
        for(int i : arr) freq[((i%k)+k)%k]++;
        for(int i=0;i<k;i++){
            if(freq[i]){
                if(i==0){ if(freq[i]&1) return 0; }
                else if(freq[i]!=freq[k-i]) return 0;
                else freq[i]=freq[k-i]=0;
            }
        }
        return 1;
    }
        
    
};