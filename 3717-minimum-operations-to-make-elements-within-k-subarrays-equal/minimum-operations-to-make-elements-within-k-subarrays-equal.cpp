class Solution {
public:
    multiset<long long> lo, hi;
    long long sumLo = 0, sumHi = 0;

    void balance() {
        int target = (lo.size() + hi.size() + 1) / 2;

        while (lo.size() > target) {
            auto it = prev(lo.end());
            long long val = *it;

            sumLo -= val;
            lo.erase(it);

            hi.insert(val);
            sumHi += val;
        }

        while (lo.size() < target) {
            auto it = hi.begin();
            long long val = *it;

            sumHi -= val;
            hi.erase(it);

            lo.insert(val);
            sumLo += val;
        }
    }

    void add(long long val) {
        if (lo.empty() || val <= *lo.rbegin()) {
            lo.insert(val);
            sumLo += val;
        } 
        else {
            hi.insert(val);
            sumHi += val;
        }

        balance();
    }

    void remove(long long val) {
        auto it = lo.find(val);

        if (it != lo.end()) {
            lo.erase(it);
            sumLo -= val;
        } 
        else {
            it = hi.find(val);
            hi.erase(it);
            sumHi -= val;
        }

        balance();
    }

    long long getCost() {
        long long median = *lo.rbegin();

        return median * lo.size() - sumLo
             + sumHi - median * hi.size();
    }

    long long minOperations(vector<int>& nums, int x, int k) {
        int n = nums.size();

        vector<long long> cost(n - x + 1);

        // Sliding window cost
        for (int i = 0; i < n; i++) {
            add(nums[i]);

            if (i >= x) {
                remove(nums[i - x]);
            }

            if (i >= x - 1) {
                cost[i - x + 1] = getCost();
            }
        }

        // DP
        const long long INF = 1e18;

        vector<vector<long long>> dp(
            n + 1, vector<long long>(k + 1, INF)
        );

        for (int i = 0; i <= n; i++) {
            dp[i][0] = 0;
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= k; j++) {

                dp[i][j] = dp[i - 1][j];

                if (i >= x && dp[i - x][j - 1] != INF) {
                    dp[i][j] = min(
                        dp[i][j],
                        dp[i - x][j - 1] + cost[i - x]
                    );
                }
            }
        }

        return dp[n][k];
    }
};