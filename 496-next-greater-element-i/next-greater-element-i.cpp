class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n = nums2.size();
        stack<int> st;
        unordered_map<int, int>mpp;
        vector<int> nge(n,-1);
        for(int i=n-1; i>=0; i--){
            while( !st.empty() && st.top()<= nums2[i]) st.pop();
            if(st.empty()) mpp[nums2[i]] = -1;
            else mpp[nums2[i]] = st.top();
            st.push(nums2[i]);
        }
        vector<int> ans;
        int m = nums1.size();
        for(int i=0; i<m; i++){
            ans.push_back(mpp[nums1[i]]);
        }
        return ans;
    }
};