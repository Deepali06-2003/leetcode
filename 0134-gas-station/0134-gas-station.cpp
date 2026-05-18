class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {

        int n = gas.size();
        int t_gas=0, t_cost=0;

        for(int i=0;i<n;i++){
            t_gas = t_gas + gas[i];
            t_cost = t_cost + cost[i];
        }

        if(t_cost > t_gas) return -1;

        int ans = 0;
        int c=0;
        for(int i=0;i<n;i++){
           c = c - cost[i] + gas[i];

            if(c<0) {
                c=0;
                ans = i+1;
            }
        }
        return ans;
    }
};