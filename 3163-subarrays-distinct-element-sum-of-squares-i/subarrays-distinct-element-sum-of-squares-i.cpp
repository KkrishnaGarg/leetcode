class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for(int i=0; i<n; i++){
            unordered_set<int> st;
            int unique = 0;
            for(int j=i; j<n; j++){
                if(!st.count(nums[j])) unique++;
                st.insert(nums[j]);
                sum += unique*unique;
            }
        }
        return sum;
    }
};