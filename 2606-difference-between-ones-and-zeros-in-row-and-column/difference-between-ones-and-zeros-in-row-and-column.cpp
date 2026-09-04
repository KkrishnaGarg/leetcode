class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0]. size();
        vector<vector<int>> ans(n, vector<int>(m));
        vector<int> onesRow(n), onesCol(m), zerosRow(n), zerosCol(m);
        for(int i=0; i<n; i++){
            int one_cnt=0, zero_cnt=0;
            for(int j= 0; j<m; j++){
                if(grid[i][j]==0) zero_cnt++;
                else one_cnt++;
            }
            onesRow[i] = one_cnt;
            zerosRow[i] = zero_cnt;
        }
        for(int i=0; i<m; i++){
            int one_cnt=0, zero_cnt=0;
            for(int j= 0; j<n; j++){
                if(grid[j][i]==0) zero_cnt++;
                else one_cnt++;
            }
            onesCol[i] = one_cnt;
            zerosCol[i] = zero_cnt;
        }
        for(int i=0; i<n; i++){
            for(int j= 0; j<m; j++){
                int diff = onesRow[i] + onesCol[j] - zerosRow[i] - zerosCol[j];
                ans[i][j] = diff;
            }
        }
        return ans;
    }
};