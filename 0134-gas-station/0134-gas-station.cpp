class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        
        int n = gas.size();
        int t_cost = accumulate(cost.begin(), cost.end() , 0);
        int t_gas = accumulate(gas.begin() , gas.end() , 0);

        if(t_cost > t_gas) return -1;

        int result = 0, total = 0;

        for(int i =0;i<n;i++){

            total = total + gas[i] - cost[i];

            if(total < 0){
                total = 0;
                result = i+1;
            }
        }
        return result;
    }
};