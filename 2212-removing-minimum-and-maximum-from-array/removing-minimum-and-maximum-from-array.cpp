class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int min_ind = 0, max_ind = 0;
        int n = nums.size();
        for(int i=0; i<n; i++){
            if(nums[min_ind] < nums[i]) min_ind = i;
            if(nums[max_ind] > nums[i]) max_ind = i;
        }
        int ans1 = min(min_ind, max_ind) + 1 + n - max(min_ind, max_ind);
        int ans2 = 1 + max(min_ind, max_ind);
        int ans3 = n - min(min_ind, max_ind);
        return min(ans1, min(ans2, ans3));
    }
};