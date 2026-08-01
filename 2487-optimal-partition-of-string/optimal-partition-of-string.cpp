class Solution {
public:
    int partitionString(string s) {
        unordered_set<char> st;
        int ans = 1;

        for (char c : s) {
            if (st.count(c)) {
                ans++;
                st.clear();
            }
            st.insert(c);
        }

        return ans;
    }
};