class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int, int> mpp;
        queue<int> q;
        int n = nums.size();
        int size = 0;
        for(int i=0; i<n; i++){
            while(mpp[nums[i]] > k-1){
                mpp[nums[q.front()]]--;
                q.pop();
            }
            if(q.empty()) size = max(size, 1);
            else size = max(size, i-q.front()+1);
            q.push(i);
            mpp[nums[i]]++;
        }
        return size;
    }
};