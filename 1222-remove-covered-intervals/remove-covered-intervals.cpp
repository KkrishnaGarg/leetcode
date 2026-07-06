class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        int n = intervals.size();
        vector<vector<int>> ans;
        for(int i=0; i<n; i++){
            if(ans.empty() || ((intervals[i][1] > ans.back()[1]) && (ans.back()[0] != intervals[i][0])))
                ans.push_back(intervals[i]);
            else if((ans.back()[0] == intervals[i][0]) && (ans.back()[1] < intervals[i][1]))
                ans.back()[1] = intervals[i][1];
        }
        return ans.size();
    }
};