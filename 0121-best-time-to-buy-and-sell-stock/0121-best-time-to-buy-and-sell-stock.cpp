class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int ans =0;
        int p = INT_MAX;
        
        for(int i :prices){
            p = min(p, i);
            ans = max(ans , i-p);
        }

        return ans;
    }
};