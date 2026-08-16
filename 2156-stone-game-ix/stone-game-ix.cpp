class Solution {
public:
    bool stoneGameIX(vector<int>& stones) {
        int cnt[3] = {0};
        for(auto &x : stones){
            cnt[x%3]++;
        }
        if (cnt[0] % 2 == 0)
            return min(cnt[1], cnt[2]) > 0;
        else
            return abs(cnt[1] - cnt[2]) > 2;
    }
};