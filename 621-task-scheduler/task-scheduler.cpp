class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> hash(26);
        for(auto &c : tasks) hash[c-'A']++;
        priority_queue<int> pq;
        for(auto &h : hash){
            if(h>0) pq.push(h);
        }
        int time = 0;
        while(!pq.empty()){
            vector<int> temp;
            for(int i=0; i<n+1; i++){
                if(!pq.empty()){
                    int freq = pq.top();
                    pq.pop();
                    freq--;
                    temp.push_back(freq);
                }
            }
            for(auto &t : temp){
                if(t>0) pq.push(t);
            }
            if(!pq.empty()) time += n+1;
            else time += temp.size();
        }
        return time;
    }
};