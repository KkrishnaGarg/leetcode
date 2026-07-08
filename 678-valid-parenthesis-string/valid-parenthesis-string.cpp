class Solution {
public:
    bool checkValidString(string s) {
        int mincnt = 0, maxcnt = 0;
        for (char c : s) {
            if (c == '(') {
                mincnt++;
                maxcnt++;
            } 
            else if (c == ')') {
                mincnt--;
                maxcnt--;
            } 
            else {
                mincnt--;
                maxcnt++;
            }
            if (maxcnt < 0) return false;
            mincnt = max(mincnt, 0);
        }

        return (mincnt == 0);
    }
};