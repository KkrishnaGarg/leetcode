class Solution {
public:
    int minOperations(string s) {
        string str = s;
        sort(str.begin(), str.end());
        int n = s.size();
        if(n<=2){
            if(str == s) return 0;
            else return -1;
        }
        if(str == s) return 0;
        if(s[0]==str[0] || s[n-1]==str[n-1]) return 1;
        if(s[0]==str[n-1] && str[0]==s[n-1] && str[0]!=str[1] && str[n-1]!=str[n-2]) return 3;
        return 2;
    }
};