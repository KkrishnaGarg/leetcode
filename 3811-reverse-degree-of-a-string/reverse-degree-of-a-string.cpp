class Solution {
public:
    int reverseDegree(string s) {
        int ans = 0;
        int i = 1;
        for(auto &c : s){
            ans += i*(int)(26-c+'a');
            i++;
        }
        return ans;
    }
};