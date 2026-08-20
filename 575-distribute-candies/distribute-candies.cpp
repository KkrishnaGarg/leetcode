class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        unordered_set<int> st;
        int n = candyType.size();
        for(auto &c: candyType){
            st.insert(c);
        }
        return min(n/2, (int)st.size());
    }
};