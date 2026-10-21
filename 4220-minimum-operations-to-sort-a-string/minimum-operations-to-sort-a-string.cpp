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
        char a=s[0], b=s[n-1], c=str[0], d=str[n-1]; 
        if(str == s) return 0;
        if(a==c || b==d) return 1;
        if(a==d && c==b && c!=str[1] && d!=str[n-2]) return 3;
        return 2;
    }
};