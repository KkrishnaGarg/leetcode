class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int, int> mpp;
        int l = 0;
        int size = 0;
        int n = nums.size();

        for (int r=0; r<n; r++) {
            mpp[nums[r]]++;

            while (mpp[nums[r]] > k) {
                mpp[nums[l]]--;
                l++;
            }

            size = max(size, r - l + 1);
        }

        return size;
    }
};