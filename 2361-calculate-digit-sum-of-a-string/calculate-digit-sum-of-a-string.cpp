class Solution {
public:
    string digitSum(string s, int k) {
        while(s.size()>k){
            int n = s.size();
            int groups = n/k;
            string str = "";
            for(int i=0; i<groups; i++){
                int sum = 0;
                for(int j=0; j<k; j++){
                    sum += s[i*k + j] - '0';
                }
                str += to_string(sum);
            }
            int sum = 0;
            for(int i=groups*k; i<n; i++){
                sum += s[i] - '0';
            }
            if(groups*k < n) str += to_string(sum);

            s = str;
        }
        return s;
    }
};