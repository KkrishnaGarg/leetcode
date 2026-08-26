class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n = s.size();
        int i = 0;
        int cnt = 0;
        string ans = "";

        for (int j = 0; j < n; j++) {

            if (s[j] == '1') cnt++;

            while (cnt == k) {

                while (i <= j && s[i] == '0') i++;

                string temp = s.substr(i, j - i + 1);

                if (ans == "" || temp.size() < ans.size() || (temp.size() == ans.size() && temp < ans)) ans = temp;

                if (s[i] == '1') cnt--;

                i++;
            }
        }

        return ans;
    }
};