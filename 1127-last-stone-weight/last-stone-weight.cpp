class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        while(stones.size()>1){
            sort(stones.begin(), stones.end());
            int n = stones.size();
            if(n==1) break;
            else if(n==2 && stones[0]==stones[1]) return 0;
            int substitute = stones[n-1] - stones[n-2];
            stones.pop_back();
            stones.pop_back();
            if(substitute > 0) stones.push_back(substitute);
        }
        return stones[0];
    }
};