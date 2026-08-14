class Solution {
public:
    int maximumLengthSubstring(string s) {
        unordered_map<int, int> mpp;
        int l = 0;
        int size = 0;
        int n = s.size();

        for (int r=0; r<n; r++) {
            mpp[s[r]]++;

            while (mpp[s[r]] > 2) {
                mpp[s[l]]--;
                l++;
            }

            size = max(size, r - l + 1);
        }

        return size;
    }
};