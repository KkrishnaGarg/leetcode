class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int> brr;
        int n = arr.size();
        int x =0;
        for(int i=0; i<n; i++){
            x = x ^ arr[i];
            brr.push_back(x);
        }
        vector<int> ans;
        n = queries.size();
        for(int i=0; i<n; i++){
            if(queries[i][0] == queries[i][1]) 
                ans.push_back(arr[queries[i][0]]);
            else if(queries[i][0] != 0)
                ans.push_back((brr[queries[i][0] - 1]) ^ brr[queries[i][1]]);
            else
                ans.push_back(brr[queries[i][1]]);
        }
        return ans;
    }
};