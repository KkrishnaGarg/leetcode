class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> rightMin(n);
        int large = INT_MIN, small = INT_MAX;
        for(int i=0; i<n; i++){
            small = min(small, nums[n-1-i]);
            rightMin[n-1-i] = small;
        }
        for(int i=0; i<n; i++){
            large = max(large, nums[i]);
            int diff = large-rightMin[i];
            if(diff<=k) return i;
        }
        return -1;
    }
};