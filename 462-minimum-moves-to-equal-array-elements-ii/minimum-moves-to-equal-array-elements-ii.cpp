class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        if(nums[0]==nums[n-1]) return 0;
        if(n%2==1){
            int cnt = 0;
            for(int i=0; i<n; i++){
                cnt += abs(nums[i]-nums[n/2]);
            }
            return cnt;
        }
        else{
            int cnt1 = 0;
            for(int i=0; i<n; i++){
                cnt1 += abs(nums[i]-nums[n/2]);
            }
            int cnt2 = 0;
            for(int i=0; i<n; i++){
                cnt2 += abs(nums[i]-nums[n/2 - 1]);
            }
            return min(cnt1, cnt2);
        }
        return -1;
    }
};