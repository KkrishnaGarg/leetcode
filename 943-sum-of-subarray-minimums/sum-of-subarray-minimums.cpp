class Solution {
public:

    const static int mod = 1e9+7;

    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();

        vector<int> nsee(n);
        stack<int> st;
        for(int i=n-1; i>=0; i--){
            while( !st.empty() && arr[st.top()]>arr[i]) st.pop();
            if(st.empty()) nsee[i]=n;
            else nsee[i]=st.top();
            st.push(i);
        }

        vector<int> psee(n);
        stack<int> stt;
        for(int i=0; i<n; i++){
            while( !stt.empty() && arr[stt.top()]>=arr[i]) stt.pop();
            if(stt.empty()) psee[i]=-1;
            else psee[i]=stt.top();
            stt.push(i);
        }

        int sum = 0;
         for(int i=0; i<n; i++){
            sum = (sum + (1ll * arr[i] * (nsee[i]-i) * (i-psee[i]))%mod )%mod;
         }
         return sum;
    }
};