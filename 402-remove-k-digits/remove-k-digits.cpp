class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> st;
        for(auto c : num){
            while(!st.empty() && k>0 && st.top()>c){
                st.pop();
                k--;
            }
            st.push(c);
        }
        while(k>0){
            st.pop();
            k--;
        }
        if(st.empty()) return "0";
        string ans = "";
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        while(ans.size() && ans.back()=='0') ans.pop_back();
        if(ans.empty()) return "0";
        reverse(ans.begin(), ans.end());
        return ans;
    }
};