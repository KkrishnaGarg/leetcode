class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int originalLength = s.size();

        int ones = 0;
        for (char c : s)
            if (c == '1') ones++;

        string t = "1" + s + "1";

        vector<vector<int>> runs;

        int cnt = 1;
        for (int i = 1; i < t.size(); i++) {
            if (t[i] == t[i - 1]) {
                cnt++;
            } else {
                runs.push_back({t[i - 1] - '0', cnt});
                cnt = 1;
            }
        }
        runs.push_back({t.back() - '0', cnt});

        int bestGain = 0;

        for (int i = 1; i + 1 < runs.size(); i++) {
            if (runs[i][0] == 1 && runs[i - 1][0] == 0 && runs[i + 1][0] == 0) {
                bestGain = max(bestGain, runs[i - 1][1] + runs[i + 1][1]);
            }
        }

        return min(originalLength, ones + bestGain);
    }
};