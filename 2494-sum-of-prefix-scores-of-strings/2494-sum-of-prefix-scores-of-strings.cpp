class Solution {
public:
    vector<int> sumPrefixScores(vector<string>& words) {
        std::unordered_map<std::string_view, int> dict;
int len = words.size();

// Precompute all possible prefixes and their counts using std::string_view
for (const auto& word : words) {
    int lenw = word.length();
    for (int k = 1; k <= lenw; ++k) {
        std::string_view prefix(word.c_str(), k);
        dict[prefix]++;
    }
}

std::vector<int> res(len);
// Compute the result for each word
for (int i = 0; i < len; ++i) {
    int lenw = words[i].length();
    int count = 0;
    for (int k = 1; k <= lenw; ++k) {
        std::string_view prefix(words[i].c_str(), k);
        count += dict[prefix];
    }
    res[i] = count;
}

return res;
        
    }
};