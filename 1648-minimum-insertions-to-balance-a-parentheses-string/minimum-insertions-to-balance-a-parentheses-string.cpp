class Solution {
public:
    int minInsertions(string s) {
        int n = s.size();
        int ans = 0;
        int cnt = 0;
        for(int i=0; i<n; i++){
            if(i==n-1){
                if(s[i]==')'){
                    if(cnt>0) cnt -= 1;
                    else ans += 2;
                }
                else cnt += 2;
            }
            else{
                if(s[i]=='(') cnt += 2;
                else{
                    if(s[i+1]==')'){
                        i++;
                        if(cnt>0) cnt -= 2;
                        else ans += 1;
                    }
                    else{
                        if(cnt>0){
                            ans++;
                            cnt -= 2;
                        }
                        else ans += 2;
                    }
                }
            }
        }
        return ans + cnt;
    }
};