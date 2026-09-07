class Solution {
public:
    int distinctSubseqII(string s) {

        const int MOD = 1e9 + 7;
        int n = s.length();

        vector<long long> dp(n + 1, 0);

        // dp[0] = 1 represents the empty subsequence
        dp[0] = 1;

        // last[c] = dp value before the previous occurrence of character c
        vector<long long> last(26, 0);

        for (int i = 0; i < n; i++) {

            int c = s[i] - 'a';

            // Add s[i] to every existing subsequence
            dp[i + 1] = (2 * dp[i]) % MOD;

            // Remove duplicate subsequences
            dp[i + 1] = (dp[i + 1] - last[c] + MOD) % MOD;

            // Store current dp value for future duplicate removal
            last[c] = dp[i];
        }

        // Remove empty subsequence
        return (dp[n] - 1 + MOD) % MOD;
    }
};