class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end(), cust);
        int cnt = 0, free = intervals[0][1];
        for(int i=0; i<n; i++){
            if(i==0 || intervals[i][0]>=free){
                cnt++;
                free = intervals[i][1];
            }
        }
        return n-cnt;
    }
    static bool cust(vector<int>&v1, vector<int>&v2){
        if(v1[1]<v2[1]) return true;
        return false;
    }
};