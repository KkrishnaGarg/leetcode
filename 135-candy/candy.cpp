class Solution {
public:
    int candy(vector<int>& ratings) {

        int n = ratings.size();
        int sum = 1;

        int i = 1;
        while (i < n) {
            // Skip equal ratings, no need to change candy count
            if (ratings[i] == ratings[i - 1]) {
                i++;
                sum++;
                continue;
            }

            // Initialize increasing slope counter
            int peak = 1;
            // Traverse strictly increasing ratings
            while (i < n && ratings[i] > ratings[i - 1]) {
                peak++;
                sum += peak;
                i++;
            }

            // Initialize decreasing slope counter
            int down = 1;
            // Traverse strictly decreasing ratings
            while (i < n && ratings[i] < ratings[i - 1]) {
                sum += down;
                i++;
                down++;
            }

            if(down>peak) sum += down-peak;
        }

        return sum;
    }
};