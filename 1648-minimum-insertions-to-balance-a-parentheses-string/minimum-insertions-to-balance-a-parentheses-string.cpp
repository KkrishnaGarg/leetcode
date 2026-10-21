class Solution {
public:
    int minInsertions(string s) {
        int n = s.size();
        int ans = 0, cnt = 0;
        for(int i=0; i<n; i++){
            if(s[i]=='(') cnt+=2;
            else{
                if(i<n-1){
                    if(s[i+1]==')'){
                        if(cnt>0) cnt-=2;
                        else ans++;
                        i++;
                    }
                    else{
                        if(cnt>0){
                            cnt-=2;
                            ans++;
                        }
                        else ans+=2;
                    }
                }
                else{
                   if(cnt>0){
                        cnt-=2;
                        ans++;
                    }
                    else ans+=2; 
                }
            }
        }
        return cnt+ans;
    }
};