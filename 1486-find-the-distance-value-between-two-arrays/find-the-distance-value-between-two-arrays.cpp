class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        sort(arr2.begin(), arr2.end());
        int n = arr2.size(), cnt = 0;
        for(auto &a : arr1){
            int lb = lower_bound(arr2.begin(), arr2.end(), a) - arr2.begin();
            if(lb==n && abs(a-arr2[n-1])<=d) continue;
            else if(lb==0 && abs(arr2[lb]-a)<=d) continue;
            else if(lb!=0 && (abs(arr2[lb]-a)<=d || abs(a-arr2[lb-1])<=d)) continue;
            cnt++;
        }
        return cnt;
    }
};