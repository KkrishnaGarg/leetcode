class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        set<int> st;

        for (int x : arr)
            st.insert(x);

        unordered_map<int, int> rank;
        int r = 1;

        for (int x : st) {
            rank[x] = r++;
        }

        for (int &x : arr) {
            x = rank[x];
        }

        return arr;
    }
};