class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        unordered_set<char> allowedChars(allowed.begin(), allowed.end());
    return count_if(words.begin(), words.end(), [&allowedChars](const string& word) {
        return all_of(word.begin(), word.end(), [&allowedChars](char ch) {
            return allowedChars.contains(ch);
        });
    });
        
    }
};