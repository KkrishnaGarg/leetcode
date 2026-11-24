class Solution {
public:
    int maxLength(vector<int>& nums) {
        int len = 0;
        for(int i = 0; i < nums.size(); i++) {
            long long pro = nums[i], g = nums[i], l = nums[i];
            for(int j = i + 1; j < nums.size(); j++) {
                pro = pro * nums[j];
                g = gcd(g, nums[j]);
                l = lcm(l, nums[j]);
                if(pro > g * l) break;
                if(pro == g * l) len = max(len, j - i + 1);
            }
        }
        return len;
    }
};