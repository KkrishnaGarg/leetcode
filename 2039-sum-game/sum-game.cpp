class Solution {
public:
    bool sumGame(string num) {
        int n = num.size();

        int a=0, b=0;
        for(int i=0; i<n; i++){
            if(num[i] == '?'){
                if(i<n/2) b++;
                else a++;
            }
        }

        int before_half = 0, after_half = 0;
        for(int i=0; i<n; i++){
            if(i < n/2 && num[i]!='?') before_half += num[i] - '0';
            else if(i >= n/2 && num[i]!='?') after_half += num[i] - '0';
        }

        if(a+b==0) return before_half != after_half;
        else if((a+b)%2==1) return true;
        else{
            if(a==b){
                if(before_half!=after_half) return true; // alice win
                else return false; // bob win
            }
            else{
                if ((a>b && after_half >= before_half)||(a<b && after_half <= before_half)) return true; // alice win
                int ab = abs(before_half - after_half);
                if(a>b){
                    if(ab==(a-b)/2 * 9) return false; // bob win
                }
                else if(a<b){
                    if(ab==(b-a)/2 * 9) return false; // bob win
                }
            }
        }
        return true; // alice win
    }
};