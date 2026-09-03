class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int min_odd = -1;
        int min_even = -1;
        for(auto &x : nums1){
            if(x&1){
                if(min_odd == -1) min_odd = x;
                else min_odd = min(x, min_odd);
            }
            else {
                if(min_even == -1) min_even = x;
                else min_even = min(x, min_even);
            }
        }
        if(min_odd==-1 || min_even==-1) return true;
        else if(min_odd!=-1 && min_even!=-1) return min_even > min_odd;
        return false;
    }
};