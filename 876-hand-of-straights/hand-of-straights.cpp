class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();

        if(n % groupSize !=0) return false;
        
        int x = n / groupSize;
        map<int, int> mpp;
        
        for(auto h : hand){
            mpp[h]++;
        }
        
        vector<vector<int>> v;
        
        for(int i=0; i<x; i++){
            vector<int>inner;
            int cnt = 0;
            for (auto it = mpp.begin(); it != mpp.end() && cnt < groupSize; ) {
                inner.push_back(it->first);
                it->second--;

                cnt++;

                if (it->second == 0)
                    it = mpp.erase(it);
                else
                    it++;
            }
            v.push_back(inner);    
        }

        for(int i=0; i<x; i++){
            if(v[i].size() != groupSize) return false;
            for(int j=1; j<groupSize; j++){
                if(v[i][j]-v[i][j-1] != 1) return false;
            }
        }
        return true;
    }
};