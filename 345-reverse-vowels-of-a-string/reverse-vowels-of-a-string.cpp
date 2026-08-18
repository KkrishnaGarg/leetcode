class Solution {
public:
    string reverseVowels(string s) {
        int n = s.size();
        vector<int> index;
        for(int i=0; i<n; i++){
            if(s[i]=='A' || s[i]=='E' || s[i]=='I' || s[i]=='O' || s[i]=='U' || s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u') index.push_back(i);
        }
        int l=0, r=index.size()-1;
        while(l<r){
            swap(s[index[l]], s[index[r]]);
            l++;
            r--;
        }
        return s;
    }
};