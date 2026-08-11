class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int sum = nums[0];
        int n = nums.size();

        int i = 0;
        int j = 1;

        while(j<n)
        {
           if (nums[j] - nums[i] == 1)
           {
             sum += nums[j];
             i++;
             j++;
           }
            else
            {
              break;
            }
                
        }
            
        

        unordered_map<int, int> mpp;
        for(auto x : nums) mpp[x]++;

        while (mpp[sum])
            sum++;

        return sum;
    }
};