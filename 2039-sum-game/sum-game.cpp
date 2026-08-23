class Solution {
public:
    bool sumGame(string num) {
        int n = num.size();

        int leftQ = 0, rightQ = 0;
        int leftSum = 0, rightSum = 0;

        for (int i = 0; i < n; i++) {
            if (num[i] == '?') {
                if (i < n / 2)
                    leftQ++;
                else
                    rightQ++;
            }
            else {
                if (i < n / 2)
                    leftSum += num[i] - '0';
                else
                    rightSum += num[i] - '0';
            }
        }

        // No '?' just check sum
        if (leftQ + rightQ == 0)
            return leftSum != rightSum;

        // Odd number of '?' alice always wins
        if ((leftQ + rightQ) % 2)
            return true;

        // Same number of '?' (whatever alice change bob will do so if sum is equal)
        if (leftQ == rightQ)
            return leftSum != rightSum;

        // Right side has more '?' and already has >= sum (alice will increase all by 9)
        if (rightQ > leftQ && rightSum >= leftSum)
            return true;

        // Left side has more '?' and already has >= sum (alice will increase all by 9)
        if (leftQ > rightQ && leftSum >= rightSum)
            return true;

        // One side has more '?' but smaller sum.
        // alice will do extreme either wont change i.e. 0 or will change fully i.e. 9
        // bob will check if alice doing extreme 9, he will do 0 and vice-verse
        int sumDiff = abs(leftSum - rightSum);
        int qDiff = abs(leftQ - rightQ);

        if(sumDiff == qDiff/2 * 9) return  false; // bob wins
        else return true; // alice win
    }
};