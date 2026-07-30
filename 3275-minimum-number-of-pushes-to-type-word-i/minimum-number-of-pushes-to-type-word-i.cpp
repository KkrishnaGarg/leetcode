class Solution {
public:
    int minimumPushes(string word) {
        int n = word.size();
        int q = n / 8;
        int r = n % 8;
        return 4 * q * (q + 1) + r * (q + 1);
    }
};