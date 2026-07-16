class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int M=0, n=nums.size();
        for(int& x: nums){
            M=max(x, M);
            x=gcd(x, M);
        }
        sort(nums.begin(), nums.end());

        int l=0, r=n-1;
        long long sum = 0;
        while(l<r){
            sum += gcd(nums[l], nums[r]);
            l++;
            r--;
        }
        return sum;

    }
};