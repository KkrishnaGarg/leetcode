class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> ans;
        string s = "123456789";
        int num;
        for(int i=2; i<10; i++){
            for(int j=0; j<=9-i; j++){
                num = stoi(s.substr(j, i));
                if(num >= low && num <= high){
                    ans.push_back(num);
                }
            }
            if(num > high) break;
        }
        return ans;
    }
};