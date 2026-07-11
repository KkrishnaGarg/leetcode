class Solution {
public:

    const int MOD = 1e9 + 7;

    int countNicePairs(vector<int>& nums) {
        vector<int> numMinusRev;
        int len = nums.size();
        for(int i=0; i<len; i++){
            int x = nums[i];
            int n=0;
            while(x!=0){
                if(n > INT_MAX/10 || n < INT_MIN/10) return 0;
                n = n*10 + x%10;
                x /= 10;
            }
            numMinusRev.push_back(nums[i]-n);
        }
        
        unordered_map<int, int> mpp;
        for(int i=0; i<len; i++){
            mpp[numMinusRev[i]]++;
        }

        long long cnt = 0;

        for (auto m : mpp) {
            cnt = (cnt + 1LL * m.second * (m.second - 1) / 2) % MOD;
        }

        return cnt;
    }
};