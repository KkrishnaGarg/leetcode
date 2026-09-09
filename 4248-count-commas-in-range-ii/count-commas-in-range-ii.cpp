class Solution {
public:
    long long countCommas(long long n) {
        long long ans = 0;
        long long comma = 1;
        long long x = 1000;

        while (x <= n) {
            long long end = min(n, x * 1000 - 1);

            ans += (end - x + 1) * comma;

            x *= 1000;
            comma++;
        }

        return ans;
    }
};

// class Solution {
// public:
//     long long countCommas(long long n) {
//         long long ans = 0;
//         long long comma = 1;
//         for (long long x = 1000; x <= n; x *= 1000) {
//             long long end = min(n, x * 1000 - 1);
//             ans += (end - x + 1) * comma;
//             comma++;
//         }

//         return ans;
//     }
// };