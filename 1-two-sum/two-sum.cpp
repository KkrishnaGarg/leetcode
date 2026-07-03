class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
    
    vector<int> ans;
    unordered_map<int, int> mpp;
    for(int i=0; i<nums.size(); i++){
        int a = nums[i];
        int more = target - a;
        if(mpp.find(more) != mpp.end()){
            ans.emplace_back(mpp[more]);
            ans.emplace_back(i);
        }
        mpp[a] = i;
    }        
    return ans;
   
    }
};