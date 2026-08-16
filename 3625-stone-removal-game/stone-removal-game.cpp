class Solution {
public:
    bool canAliceWin(int n) {
        int take = 10;
        int moves = 0;
        while (n >= take) {
            n -= take;
            take--;
            moves++;
        }
        return moves % 2 == 1;
    }
};