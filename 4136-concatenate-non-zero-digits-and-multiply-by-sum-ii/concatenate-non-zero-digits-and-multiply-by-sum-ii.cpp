class Solution {
public:
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        const int MOD = 1e9 + 7;

        int n = s.size();

        // Original positions of non-zero digits
        vector<int> pos;

        // Non-zero digits
        vector<int> digit;

        for (int i = 0; i < n; i++) {
            if (s[i] != '0') {
                pos.push_back(i);
                digit.push_back(s[i] - '0');
            }
        }

        int m = digit.size();

        // powers of 10
        vector<long long> power(m + 1, 1);
        for (int i = 1; i <= m; i++)
            power[i] = (power[i - 1] * 10) % MOD;

        // prefix hash (number)
        vector<long long> prefNum(m + 1, 0);

        // prefix digit sum
        vector<long long> prefSum(m + 1, 0);

        for (int i = 1; i <= m; i++) {
            prefNum[i] = (prefNum[i - 1] * 10 + digit[i - 1]) % MOD;
            prefSum[i] = prefSum[i - 1] + digit[i - 1];
        }

        vector<int> ans;

        for (auto &q : queries) {
            int l = q[0];
            int r = q[1];

            // first non-zero >= l
            int L = lower_bound(pos.begin(), pos.end(), l) - pos.begin();

            // last non-zero <= r
            int R = upper_bound(pos.begin(), pos.end(), r) - pos.begin() - 1;

            if (L > R) {
                ans.push_back(0);
                continue;
            }

            int len = R - L + 1;

            long long x =
                (prefNum[R + 1] -
                 prefNum[L] * power[len] % MOD +
                 MOD) % MOD;

            long long sum = prefSum[R + 1] - prefSum[L];

            ans.push_back((x * (sum % MOD)) % MOD);
        }

        return ans;
    }
};