class Solution {
public:
    int findGCD(vector<int>& nums) {
        int nMin = INT_MAX;
        int nMax = INT_MIN;
        for(auto x : nums){
            nMin = min(x, nMin);
            nMax = max(x, nMax);
        }
        return (gcd(nMin, nMax));
    }
};