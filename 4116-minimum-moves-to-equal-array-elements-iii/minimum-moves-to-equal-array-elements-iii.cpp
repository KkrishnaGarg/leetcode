class Solution {
public:
    int minMoves(vector<int>& nums) {
        long long sum = 0;
        int largest = INT_MIN;
        int n = nums.size();
        for(auto  &x : nums){
            sum += x;
            largest = max(largest, x);
        }
        return 1ll*n*largest - sum;
    }
};