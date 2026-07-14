class Solution {
public:
    int reverseBits(int n) {
        string s = "";
        while(n >0){
            if(n & 1) s +='1';
            else s +='0';
            n >>= 1;
        }

        while(s.size() <32){
            s += '0';
        }

        long long num = 0, adder=1;
        for(int i=s.size()-1; i>=0; i--){
            if(s[i]=='1') num += adder;
            adder <<= 1;
        }
        return num;
    }
};