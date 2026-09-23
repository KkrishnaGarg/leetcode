class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        int k = 0;
        for(auto &e : nums) k += e;
        k = k-x;
        if (k < 0) return -1;
        if (k == 0) return n;

        int best = -1, i = 0, sum = 0;
        for (int j = 0; j < n; j++) {
            sum += nums[j];
            while (sum > k){
                sum -= nums[i];
                i++;
            }

            if (sum == k) best = max(best, j - i + 1);
        }
        if(best==-1) return -1;
        return n - best;
    }
};