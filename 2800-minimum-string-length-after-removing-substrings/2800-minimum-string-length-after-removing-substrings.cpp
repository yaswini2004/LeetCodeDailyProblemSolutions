class Solution {
public:
    int minLength(string s) {
        int stack_ptr = -1;
        for (char c : s) {
            if (stack_ptr == -1) {
                s[++stack_ptr] = c;
            } else if ((c == 'B' && s[stack_ptr] == 'A') ||
                       (c == 'D' && s[stack_ptr] == 'C')) {
                stack_ptr--;
            } else {
                s[++stack_ptr] = c;
            }
        }
        return stack_ptr + 1;
        
    }
};