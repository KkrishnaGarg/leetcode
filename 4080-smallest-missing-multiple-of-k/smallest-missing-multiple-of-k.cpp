class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_set<int> st;
        for(auto &x : nums){
            st.insert(x);
        }
        int n = st.size();
        int x = k;
        while(true){
            st.insert(x);
            if(st.size()>n) return x;
            x += k;
        }
        return -1;
    }
};