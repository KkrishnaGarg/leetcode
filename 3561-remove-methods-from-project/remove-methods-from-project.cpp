class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<vector<int>> graph(n);

        // Build graph
        for (auto &edge : invocations) {
            graph[edge[0]].push_back(edge[1]);
        }

        // Find all suspicious methods
        vector<bool> suspicious(n, false);

        function<void(int)> dfs = [&](int node) {
            suspicious[node] = true;
            for (int next : graph[node]) {
                if (!suspicious[next])
                    dfs(next);
            }
        };

        dfs(k);

        // Check if any non-suspicious method calls a suspicious method
        for (auto &edge : invocations) {
            int u = edge[0];
            int v = edge[1];

            if (!suspicious[u] && suspicious[v]) {
                // Cannot remove suspicious methods
                vector<int> ans;
                for (int i = 0; i < n; i++)
                    ans.push_back(i);
                return ans;
            }
        }

        // Return remaining methods
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            if (!suspicious[i])
                ans.push_back(i);
        }

        return ans;
    }
};