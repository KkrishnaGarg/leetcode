class Solution {
public:
    bool checkString(string s) {
        int firstB = -1, lastA = -1;
        int n = s.size();
        for(int i=0; i<n; i++){
            if(s[i]=='a') lastA = i;
            else if(firstB==-1) firstB = i;
        }
        return (firstB>lastA || firstB==-1);
    }
};