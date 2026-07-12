class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n = arr.size();
        set<int> st;

        for (int x : arr)
            st.insert(x);

        unordered_map<int, int> rank;
        int r = 1;

        for (int x : st) {
            rank[x] = r;
            r++;
        }

        for(int i=0; i<n; i++){
            arr[i] = rank[arr[i]];
        }

        return arr;
    }
};