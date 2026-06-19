class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int N = tasks.size();
        vector<int>freq(26, 0);

        for(int i : tasks) freq[i-'A']++;

        priority_queue<int>pq;
        for(int i : freq){
            if( i != 0 )pq.push(i);
        }
        int ans=0;
        while(!pq.empty()){
           
            vector<int>curr;
            for(int i=0;i<=n; i++){
                if(!pq.empty()){
                    int f = pq.top();
                    pq.pop();

                    curr.push_back(f-1);
                }
            }

            for(int i : curr){
                if(i > 0) pq.push(i);
            }

            if(pq.empty()) ans = ans + curr.size();
            else ans = ans+ n+1;
        }

        return ans;
    }
};