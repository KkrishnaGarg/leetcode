class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mpp;
        for(auto &x : nums) mpp[x]++;
        vector<vector<int>> vec;
        for(auto i : mpp){
            vec.push_back({i.second, i.first});
        }
        sort(vec.begin(), vec.end(), greater<vector<int>>());
        vector<int>ans;
        for(int i=0; i<k; i++){
            ans.push_back(vec[i][1]);
        }
        return ans;
    }
};