class Solution {
public:
    string reverseWords(string s) {
        stack<string> st;
        string str;
        for(auto &c : s){
            if(c!=' ') str+=c;
            else if(c==' ' && str!=""){
                st.push(str);
                str = "";
            } 
        }
        if(str!="") st.push(str);
        string ans = "";
        while(!st.empty()){
            ans += st.top();
            st.pop();
            if(!st.empty()) ans += ' ';
        }
        return ans;
    }
};