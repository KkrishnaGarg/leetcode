class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for(int i=0; i<n; i++){
            vector<int> visited(101);
            int unique = 0;
            for(int j=i; j<n; j++){
                if(visited[nums[j]]==0) unique++;
                visited[nums[j]]++;
                sum += unique*unique;
            }
        }
        return sum;
    }
};