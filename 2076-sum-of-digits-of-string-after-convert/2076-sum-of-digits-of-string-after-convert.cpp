// class Solution {
// public:
//     int getLucky(string s, int k) {
        
//     }
// };
class Solution {
public:
    int getLucky(string s, int k) {
        int sumdigits = 0;
        int v0;
        for (char ch : s) {
            v0 = ch - 'a' + 1;
            sumdigits += v0 / 10 + v0 % 10;
        }
        for (int i = 1; i < k; i++) {
            v0 = 0;
            for (; sumdigits; sumdigits /= 10) {
                v0 += sumdigits % 10;
            }
            sumdigits = v0;
        }
        
        return sumdigits;
    }
};