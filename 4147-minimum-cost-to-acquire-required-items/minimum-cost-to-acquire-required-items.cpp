class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        long long minOfBoth = min(need1, need2);
        long long timeOfOwn = minOfBoth*cost1 + minOfBoth*cost2;
        long long collectiveTime = minOfBoth*costBoth;
        long long time = min(timeOfOwn, collectiveTime);
        if(need1 > need2){
            long long remaining = need1-need2;
            time += min(remaining*cost1, remaining*costBoth);
        }
        else if(need2 > need1){
            long long remaining = need2-need1;
            time += min(remaining*cost2, remaining*costBoth);
        }
        return time;
    }
};