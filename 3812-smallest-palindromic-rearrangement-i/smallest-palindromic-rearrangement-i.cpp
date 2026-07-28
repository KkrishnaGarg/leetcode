class Solution {
public:
    string smallestPalindrome(string s) {
        int n = s.size();
        int m = n/2;
        if(n&1){
            sort(s.begin(), s.begin()+m);
            for(int i=m; i<n; i++){
                s[i] = s[n-i-1];
            }
        }
        else{
            sort(s.begin(), s.begin()+m);
            for(int i=m; i<n; i++){
                s[i] = s[n-i-1];
            }
        }
        return s;
    }
};