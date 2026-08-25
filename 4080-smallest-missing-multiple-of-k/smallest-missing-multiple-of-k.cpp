class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_set<int> st;
        for(auto &x : nums){
            st.insert(x);
        }
        int x = k;
        while (st.count(x)) {
            x += k;
        }
        return x;
    }
};