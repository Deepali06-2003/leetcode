class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        
        int m = tasks.size();
        vector<int>arr(26, 0);
        for(char c : tasks)arr[c-'A']++;

        priority_queue<int>pq;
        for(int i : arr){
            if(i>0)pq.push(i);
        }

        int ans=0;
        while(!pq.empty()){
            vector<int>curr;
            for(int i =0; i<(n+1);i++){
                if(!pq.empty()){
                    int x = pq.top();
                    pq.pop();
                    x--;
                    curr.push_back(x);
                }
            }

            for(int i =0;i<curr.size();i++){
                if(curr[i]>0)pq.push(curr[i]);
            }

            if(pq.empty()) ans = ans+curr.size();
            else ans = ans+n+1;

        }

        return ans;
    }
};