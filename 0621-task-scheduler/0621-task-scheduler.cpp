class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int>freq(26, 0);
        for(char c : tasks){
            freq[c-'A'] +=1;
        }

        priority_queue<int>pq;
        for(int i=0;i<26;i++){
            if(freq[i]>0) pq.push(freq[i]);
        }

        int ans=0;

        while(!pq.empty()){
            vector<int>curr;
            for(int i=0;i<=n;i++){

                if(!pq.empty()){
                int f = pq.top();
                pq.pop();

                curr.push_back(f-1);
                }
            }

            for(int i=0;i<curr.size();i++){
                if(curr[i]>0) pq.push(curr[i]);
            }

            if(pq.empty()) ans = ans+curr.size();
            else ans = ans+n+1;
        }
        return ans;
    }
};