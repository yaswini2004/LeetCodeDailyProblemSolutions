class Solution {
public:
    int solve(int node, int &n, vector<vector<int>> &G, vector<int> &dp) {
        if(node == (n - 1)) return 0;
        if(dp[node] != -1) return dp[node];
        dp[node] = INT_MAX;
        for(auto nextNode : G[node]) dp[node] = min(dp[node], 1 + solve(nextNode, n, G, dp));
        return dp[node];
    }
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>> G(n);
        for(int i = 1; i < n; i++) G[i - 1].push_back(i);
        vector<int> ans;
        for(auto q : queries) {
            G[q[0]].push_back(q[1]);
            vector<int> dp(n, -1);
            ans.push_back(solve(0, n, G, dp));
        }
        return ans;
        
        
    }
};