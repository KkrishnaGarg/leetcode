class Solution {
public:
    vector<int> distributeCandies(int candies, int num_people) {
        vector<int> ans(num_people, 0);
        int i=0;
        int adder = 1;
        while(true){
            ans[i] += min(adder, candies);
            candies -= adder;
            if(candies<=0) break;
            adder++;
            i++;
            if(i==num_people) i=0;
        }
        return ans;
    }
};