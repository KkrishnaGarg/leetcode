class Solution {
public:
    vector<vector<int>> adj;
    vector<bool> vis;

    void dfs(int node, vector<int>& comp) {
        vis[node] = true;
        comp.push_back(node);

        for (int nei : adj[node]) {
            if (!vis[nei])
                dfs(nei, comp);
        }
    }

    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        adj.resize(n);
        vis.assign(n, false);

        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        int ans = 0;

        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                vector<int> comp;
                dfs(i, comp);

                int vertices = comp.size();
                int edgeCount = 0;

                for (int node : comp)
                    edgeCount += adj[node].size();

                edgeCount /= 2;

                if (edgeCount == vertices * (vertices - 1) / 2)
                    ans++;
            }
        }

        return ans;
    }
};