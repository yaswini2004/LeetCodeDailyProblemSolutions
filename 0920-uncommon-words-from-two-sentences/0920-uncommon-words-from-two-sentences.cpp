class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
            vector <string> words1, words2;

    stringstream check1(s1);
    string intermediate;
    while (getline(check1, intermediate, ' ')) words1.push_back(intermediate);

    stringstream check2(s2);
    while (getline(check2, intermediate, ' ')) words2.push_back(intermediate);

    unordered_map<string, int> freq;

    for (string word : words1) freq[word]++;
    for (string word : words2) freq[word]++;

    vector<string> res;

    for (auto it : freq) {

        if (it.second == 1) res.push_back(it.first);
    }

    return res;

        
    }
};