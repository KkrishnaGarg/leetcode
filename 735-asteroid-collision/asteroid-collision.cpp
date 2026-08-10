class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> ans;
        for(auto a : asteroids){
            if(a>0) ans.push_back(a);
            else{
                while(!ans.empty() && ans.back()>0 && ans.back()<-1*a) ans.pop_back();
                if(ans.empty() || ans.back()<0) ans.push_back(a);
                else if(ans.back() == -1*a) ans.pop_back();
            }
        }
        return ans;
    }
};