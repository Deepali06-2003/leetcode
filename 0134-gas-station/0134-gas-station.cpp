class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        
        int gasT=0, costT=0;
        for(int i=0;i<gas.size();i++){
            gasT += gas[i];
            costT += cost[i];
        }

        if(gasT < costT) return -1;

        int ans=0, total=0;
        for(int i=0;i<gas.size();i++){
            total = total + gas[i] - cost[i];

            if(total < 0){
                ans = i+1;
                total =0;
            }
        }
        return ans;
    }
};