class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        int n = nums.size();

        vector<int> nse(n);
        stack<int> s1;
        for(int i=n-1; i>=0; i--){
            while( !s1.empty() && nums[s1.top()]>=nums[i]) s1.pop();
            if(s1.empty()) nse[i]=n;
            else nse[i]=s1.top();
            s1.push(i);
        }

        vector<int> psee(n);
        stack<int> s2;
        for(int i=0; i<n; i++){
            while( !s2.empty() && nums[s2.top()]>nums[i]) s2.pop();
            if(s2.empty()) psee[i]=-1;
            else psee[i]=s2.top();
            s2.push(i);
        }

        long long sumMin = 0;
        for(int i=0; i<n; i++){
            sumMin += 1ll * nums[i] * (nse[i]-i) * (i-psee[i]);
        }

        vector<int> nge(n);
        stack<int> s3;
        for(int i=n-1; i>=0; i--){
            while( !s3.empty() && nums[s3.top()]<=nums[i]) s3.pop();
            if(s3.empty()) nge[i]=n;
            else nge[i]=s3.top();
            s3.push(i);
        }

        vector<int> pgee(n);
        stack<int> s4;
        for(int i=0; i<n; i++){
            while( !s4.empty() && nums[s4.top()]<nums[i]) s4.pop();
            if(s4.empty()) pgee[i]=-1;
            else pgee[i]=s4.top();
            s4.push(i);
        }

        long long sumMax = 0;
         for(int i=0; i<n; i++){
            sumMax += 1ll * nums[i] * (nge[i]-i) * (i-pgee[i]);
        }

        return sumMax-sumMin;
    }
};