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

        // if no '?' then just check sum of before and after
        if(a+b==0) return before_half != after_half;

        // if odd alice will always win
        else if((a+b)%2==1) return true;

        // in case of even
        else{

            // agar left'?' == right'?' 
            if(a==b){
                // alice will increase the greater and bob won't be able to catch
                if(before_half!=after_half) return true; // alice win
                // bob will increase same on other side what alice did
                else return false; // bob win
            }
            // agar left'?' != right'?' 
            else{// one side will have more '?' in way 2,4,6,8,10..........

                // side where we have more'?' and greater or equal sum both 
                // alice will increase all by 9
                if ((a>b && after_half >= before_half)||(a<b && after_half <= before_half)) return true; // alice win

                // side where we have more'?' and lesser sum
                // alice will do extreme either wont change i.e. 0 or will change fully i.e. 9
                // bob will check if alice doing extreme 9, he will do 0 and vice-verse
                int abs_sum = abs(before_half - after_half);
                int abs_count = abs(a-b);
                if(abs_sum == abs_count/2 * 9) return false; // bob win
            }
        }
        return true; // alice win
    }
};