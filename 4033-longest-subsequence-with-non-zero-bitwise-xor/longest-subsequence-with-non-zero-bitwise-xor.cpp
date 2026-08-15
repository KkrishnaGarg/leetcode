class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n = nums.size();
        int x = 0;
        bool allZero = false;

        for (int a : nums) {
            x ^= a;
            if (a != 0)
                allZero = true;
        }

        if (x != 0)
            return n;

        if (allZero)
            return n - 1;

        return 0;
    }
};