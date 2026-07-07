class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        vector<int> hash(2,0); // {5, 10}
        for(auto x : bills){
            if(x==5) hash[0]++;
            else if(x==10){
                if(hash[0]>0){
                    hash[0]--;
                    hash[1]++;
                    continue;
                }
                else return false;
            }
            else{
                if(hash[1]>0 && hash[0]>0){
                    hash[0]--;
                    hash[1]--;
                    continue;
                }
                else if(hash[0]>2){
                    hash[0] -= 3;
                    continue;
                }
                else return false;
            }
        }
        return true;
    }
};