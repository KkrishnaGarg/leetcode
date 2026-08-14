class Solution {
public:
    int minimumAddedCoins(vector<int>& coins, int target) {
        int reach = 0;
        int i = 0;
        int add = 0;
        sort(coins.begin(), coins.end());
        int c = coins.size();

        while(reach < target) {
            if(i < c && coins[i] <= reach + 1) {
                reach += coins[i];
                i++;
            }
            else {
                reach += reach + 1;
                add++;
            }
        }

        return add;
    }
};