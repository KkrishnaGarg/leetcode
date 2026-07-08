class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> distribution(n, 1);
        int total = 0;

        // Left to right
        for (int i = 1; i < n; i++) {
            if (ratings[i] > ratings[i - 1]) {
                distribution[i] = distribution[i - 1] + 1;
            }
        }

        // Right to left
        for (int i = n - 2; i >= 0; i--) {
            if (ratings[i] > ratings[i + 1] && distribution[i] <= distribution[i+1]) {
                distribution[i] = distribution[i + 1] + 1;
            }
            total += distribution[i];
        }
        total += distribution[n-1];
        

        return total;
    }
};