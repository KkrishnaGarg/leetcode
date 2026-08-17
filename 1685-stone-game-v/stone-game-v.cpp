class Solution {
public:
    int dp[500][500];

    int solve(int l, int r, vector<int>& prefix) {
        if (l == r)
            return 0;

        if (dp[l][r] != -1)
            return dp[l][r];

        int ans = 0;

        for (int k = l; k < r; k++) {

            int left = prefix[k + 1] - prefix[l];
            int right = prefix[r + 1] - prefix[k + 1];

            if (left < right) {
                ans = max(ans, left + solve(l, k, prefix));
            }
            else if (left > right) {
                ans = max(ans, right + solve(k + 1, r, prefix));
            }
            else {
                ans = max(ans,
                    left + max(
                        solve(l, k, prefix),
                        solve(k + 1, r, prefix)
                    )
                );
            }
        }

        return dp[l][r] = ans;
    }

    int stoneGameV(vector<int>& stoneValue) {
        int n = stoneValue.size();

        vector<int> prefix(n + 1, 0);

        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + stoneValue[i];
        }

        memset(dp, -1, sizeof(dp));

        return solve(0, n - 1, prefix);
    }
};