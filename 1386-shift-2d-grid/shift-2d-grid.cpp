class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size(); // rows
        int n = grid[0].size(); // columns
        
        k = k%(m*n);

        vector<vector<int>> ans(grid);

        if(k == 0){
            return grid;
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int oldI = i * n + j;
                int newI = (oldI + k) % (m * n);

                int row = newI / n;
                int col = newI % n;

                ans[row][col] = grid[i][j];
            }
        }
        return ans;

    }
};