class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        int n = customers.size();
        vector<int> CT(n);
        for(int i=0; i<n; i++){
            if(i==0){
                CT[i] = customers[i][0] + customers[i][1];
            }
            else{
                if(CT[i-1] >= customers[i][0]) CT[i] = CT[i-1] + customers[i][1];
                else CT[i] = customers[i][0] + customers[i][1];
            }
        }
        vector<int> WT(n);
        double sum = 0;
        for(int i=0; i<n; i++){
            WT[i] = CT[i] - customers[i][0];
            sum += WT[i];
        }

        return sum/n;
    }
};