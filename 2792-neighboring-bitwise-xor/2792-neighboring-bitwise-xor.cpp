class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int start1 = 0, start2 = 1, trueXOR = derived[0];
        for (int i = 1; i < derived.size(); i++) {
            trueXOR ^= derived[i];
        }
        if (trueXOR ^ start1 == start1) return true;
        if (trueXOR ^ start2 == start2) return true;

        return false;
        
    }
};