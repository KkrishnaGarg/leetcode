class Solution {
public:

    long long count(vector<int>& coins, long long x) {
        int n = coins.size();
        long long ans = 0;

        for (int mask = 1; mask < (1 << n); mask++) {

            long long lcm = 1;
            int bits = 0;
            bool bad = false;

            for (int i = 0; i < n; i++) {
                if (mask & (1 << i)) {
                    bits++;

                    long long g = gcd(lcm, (long long)coins[i]);
                    lcm = (lcm / g) * coins[i];

                    if (lcm > x) {
                        bad = true;
                        break;
                    }
                }
            }

            if (bad)
                continue;

            if (bits % 2 == 1)
                ans += x / lcm;
            else
                ans -= x / lcm;
        }

        return ans;
    }

    long long findKthSmallest(vector<int>& coins, int k) {

        long long left = 1;
        long long right = 1e11;

        while (left < right) {

            long long mid = left + (right - left) / 2;

            if (count(coins, mid) >= k)
                right = mid;
            else
                left = mid + 1;
        }

        return left;
    }
};