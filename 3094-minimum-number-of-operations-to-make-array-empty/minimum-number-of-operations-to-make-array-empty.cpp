class Solution {
public:
    int minOperations(vector<int>& nums) {
        unordered_map<int, int> mpp;
        for(auto x : nums){
            mpp[x]++;
        }
        int ans = 0;
        for(auto m : mpp){
            if(m.second == 1) return -1;
            else if(m.second%3==0) ans += m.second/3;
            else ans += m.second/3 + 1;
        }
        return ans;
    }
};