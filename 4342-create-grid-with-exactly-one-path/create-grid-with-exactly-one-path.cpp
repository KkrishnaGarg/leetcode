class Solution {
public:
    vector<string> createGrid(int m, int n) {
        vector<string> ans;
        string s = "";
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(i==0 || j==n-1){
                    s += '.';
                }
                else{
                    s += '#';
                }
            }
            ans.push_back(s);
            s = "";
        }
        return ans;
    }
};