class Solution {
public:
    int minMoves(vector<int>& nums) {
        int least = *min_element(nums.begin(), nums.end());
        int cnt = 0;
        for(auto &x : nums){
            cnt += x-least;
        }
        return cnt;
    }
};