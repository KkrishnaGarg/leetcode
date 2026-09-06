class Solution {
public:

    int solve(string &s, string &t, int i, int j, vector<vector<int>> &dp) {

        // t is completely formed
        if(j == t.length())
            return 1;

        // s is exhausted but t is still remaining
        if(i == s.length())
            return 0;

        if(dp[i][j] != -1)
            return dp[i][j];

        // Don't include s[i]
        int exclude = solve(s, t, i + 1, j, dp);

        int include = 0;

        // Include s[i] only if it matches t[j]
        if(s[i] == t[j])
            include = solve(s, t, i + 1, j + 1, dp);

        return dp[i][j] = include + exclude;
    }

    int numDistinct(string s, string t) {

        int n = s.length();
        int m = t.length();

        vector<vector<int>> dp(n, vector<int>(m, -1));

        return solve(s, t, 0, 0, dp);
    }
};