class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
        int mx = *max_element(nums.begin(), nums.end());

        // Frequency of each value
        vector<long long> freq(mx + 1, 0);
        for (int x : nums)
            freq[x]++;

        // cnt[g] = how many numbers are divisible by g
        vector<long long> cnt(mx + 1, 0);
        for (int g = 1; g <= mx; g++) {
            for (int multiple = g; multiple <= mx; multiple += g) {
                cnt[g] += freq[multiple];
            }
        }

        // exact[g] = number of pairs having gcd exactly g
        vector<long long> exact(mx + 1, 0);

        for (int g = mx; g >= 1; g--) {
            long long c = cnt[g];
            exact[g] = c * (c - 1) / 2;

            for (int multiple = 2 * g; multiple <= mx; multiple += g) {
                exact[g] -= exact[multiple];
            }
        }

        // Prefix sums
        vector<long long> prefix(mx + 1, 0);
        for (int g = 1; g <= mx; g++) {
            prefix[g] = prefix[g - 1] + exact[g];
        }

        vector<int> ans;
        for (long long q : queries) {
            // Queries are 0-indexed
            q++;

            int lo = 1, hi = mx;
            while (lo < hi) {
                int mid = lo + (hi - lo) / 2;
                if (prefix[mid] >= q)
                    hi = mid;
                else
                    lo = mid + 1;
            }

            ans.push_back(lo);
        }

        return ans;
    }
};