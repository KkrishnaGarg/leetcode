class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        int n = customers.size();
        vector<int> WT(n);
        double sum = 0;
        for(int i=0; i<n; i++){
            if(i==0){
                WT[i] = customers[i][1];
            }
            else{
                if(WT[i-1] >= customers[i][0] - customers[i-1][0]){
                    WT[i] = WT[i-1] + customers[i-1][0] + customers[i][1] - customers[i][0];
                }
                else WT[i] = customers[i][1];
            }

            sum += WT[i];
        }

        return sum/n;
    }
};