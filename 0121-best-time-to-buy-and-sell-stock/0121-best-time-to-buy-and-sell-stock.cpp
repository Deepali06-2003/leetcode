class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int ans =0 , buy= INT_MAX;
        for(int i : prices){
            buy = min(buy, i);
            ans = max(ans, i-buy);
        }
        return ans;
    }
};