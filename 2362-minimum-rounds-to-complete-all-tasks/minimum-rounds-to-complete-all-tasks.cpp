class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        unordered_map<int, int> mpp;
        for(auto x : tasks){
            mpp[x]++;
        }
        int ans = 0;
        for(auto m : mpp){
            if(m.second == 1) return -1;
            else ans += (m.second + 2)/3;
        }
        return ans;
    }
};