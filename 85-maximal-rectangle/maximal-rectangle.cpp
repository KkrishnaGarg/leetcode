class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.empty()) return 0;
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> box(n, vector<int>(m,0));
        for(int j=0; j<m; j++){
            for(int i=0; i<n; i++){
                if(i==0 || matrix[i][j]=='0') box[i][j] = matrix[i][j]-'0';
                else box[i][j] = box[i-1][j]+1;
            }
        }
        int ans = 0;
        for(int i=0; i<n; i++){
            ans = max(ans, largestRectangleArea(box[i]));
        }
        return ans;
    }
    
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();

        vector<int> nse(n);
        stack<int> s1;
        for(int i=n-1; i>=0; i--){
            while( !s1.empty() && heights[s1.top()]>=heights[i]) s1.pop();
            if(s1.empty()) nse[i]=n;
            else nse[i]=s1.top();
            s1.push(i);
        }

        vector<int> pse(n);
        stack<int> s2;
        for(int i=0; i<n; i++){
            while( !s2.empty() && heights[s2.top()]>=heights[i]) s2.pop();
            if(s2.empty()) pse[i]=-1;
            else pse[i]=s2.top();
            s2.push(i);
        }

        int area = heights[0];
        for(int i=0; i<n; i++){
            area = max(area, heights[i] * (nse[i]-pse[i]-1));
        }
        return area;
    }
};