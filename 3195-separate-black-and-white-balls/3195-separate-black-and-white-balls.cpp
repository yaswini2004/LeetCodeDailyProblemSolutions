class Solution {
public:
    long long minimumSteps(string s) {
        long long swaps=0, cntzero=0;
int n=s.size();

    for(int i=n-1; i>=0; i--){
        if(s[i]=='1')swaps+=cntzero;
        else cntzero++;
    }

    return swaps;
     
    }
};