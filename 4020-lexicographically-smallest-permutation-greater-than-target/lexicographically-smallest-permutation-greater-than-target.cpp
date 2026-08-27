class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        sort(s.begin(), s.end(), greater<char>());
        if (s <= target) return "";

        vector<int> hash(26);
        for (auto &c : s) hash[c - 'a']++;

        string ans = "";
        int n = s.size();

        for (int i = 0; i < n; i++) {
            int x = target[i] - 'a';

            if (hash[x]) {
                hash[x]--;
                ans += target[i];
            }
            else {
                for (int j = x + 1; j < 26; j++) {
                    if (hash[j]) {
                        ans += char('a' + j);
                        hash[j]--;

                        for (int k = 0; k < 26; k++)
                            while (hash[k]--)
                                ans += char('a' + k);

                        return ans;
                    }
                }

                while (!ans.empty()) {
                    int last = ans.back() - 'a';
                    ans.pop_back();
                    hash[last]++;

                    for (int j = last + 1; j < 26; j++) {
                        if (hash[j]) {
                            ans += char('a' + j);
                            hash[j]--;

                            for (int k = 0; k < 26; k++)
                                while (hash[k]--)
                                    ans += char('a' + k);

                            return ans;
                        }
                    }
                }
            }
        }
        if(ans==target){ 
            next_permutation(ans.begin(), ans.end()); 
            return ans;
        }
        return "just for return";
    }
};