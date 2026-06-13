class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();

        vector<int>res(n, 1);
        int p =1, s=1;
        
        for(int i =0;i<n;i++){
            res[i] = p;
            p = p*nums[i];
        }

        for(int i =(n-1) ;i>=0;i--){
            res[i] = res[i] * s;
            s = s * nums[i];
        }
        return res;
    }
};
