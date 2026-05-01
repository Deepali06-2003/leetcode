class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        
        unordered_map<char , int>mp;
        for(char c : tasks){
            mp[c]++;
        }

        priority_queue<int>pq;
        for(auto i:mp){
            pq.push(i.second);
        }

        int ans =0;

        while(!pq.empty()){
           
            vector<int>curr;
            for(int i =0;i<=n;i++){
                if(!pq.empty()){
                    int freq = pq.top();
                    pq.pop();
                    curr.push_back(freq-1);
                }
                
            }
            for(auto j : curr){
                if(j > 0)pq.push(j);
            }
            
            if(!pq.empty()) ans = ans + (n+1);
            else ans = ans+ curr.size();

        }

        return ans;
    }
};



