class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n = img1.size();

        vector<pair<int, int>> A, B;

        // Store coordinates of all 1s
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (img1[i][j] == 1)
                    A.emplace_back(i, j);

                if (img2[i][j] == 1)
                    B.emplace_back(i, j);
            }
        }

        vector<vector<int>> cnt(2 * n, vector<int>(2 * n, 0));

        int best = 0;

        for (auto& a : A) {
            for (auto& b : B) {

                int dx = b.first - a.first;
                int dy = b.second - a.second;

                // Shift because dx and dy can be negative
                int x = dx + n;
                int y = dy + n;

                cnt[x][y]++;

                best = max(best, cnt[x][y]);
            }
        }

        return best;
    }
};