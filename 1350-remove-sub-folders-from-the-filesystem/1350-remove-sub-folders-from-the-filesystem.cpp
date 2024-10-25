class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        sort(folder.begin(), folder.end());
        vector<string> roots;
        for (auto f: folder) {
            if (roots.empty() || !isSubfolderOf(f, roots.back())) {
                roots.push_back(f);
            }
        }
        return roots;
    }
    bool isSubfolderOf(const string& f, const string &root) {
        auto found = f.find(root);
        return found == 0 && f[root.length()] == '/'; 
        
    }
};