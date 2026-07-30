class Solution {
public:
    int minimumPushes(string word) {
        vector<int> hash(26, 0);
        for(auto c : word){
            hash[c-'a']++;
        }
        sort(hash.begin(), hash.end(), greater<int>());

        int sum = 0;
        for(int i=0; i<26 && hash[i]>0; i++){
            if(i<8) sum += hash[i];
            else if(i<16) sum += hash[i]*2;
            else if(i<24) sum += hash[i]*3;
            else sum += hash[i]*4;
        }
        return sum;
    }
};