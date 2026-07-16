class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefixGcd;
        int m = nums[0];
        for(int i=0; i<n; i++){
            m = max(m, nums[i]);
            prefixGcd.push_back(m);
        }
        for(int i=0; i<n; i++){
            prefixGcd[i] = gcd(prefixGcd[i], nums[i]);
        }
        sort(prefixGcd.begin(), prefixGcd.end());

        int l=0, r=n-1;
        long long sum = 0;
        while(l<r){
            sum += gcd(prefixGcd[l], prefixGcd[r]);
            l++;
            r--;
        }
        return sum;

    }
};