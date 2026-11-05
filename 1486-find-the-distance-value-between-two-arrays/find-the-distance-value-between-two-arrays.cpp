class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int n1 = arr1.size();
        int n2 = arr2.size();
        int cnt = 0;
        for(int i=0; i<n1; i++){
            int j;
            for(j=0; j<n2; j++){
                if(abs(arr1[i]-arr2[j])<=d) break;
            }
            if(j==n2) cnt++;
        }
        return cnt;
    }
};