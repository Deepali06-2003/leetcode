class Solution {
public:
    int majorityElement(vector<int>& nums) {
        
        int n = nums.size();
        int ans = nums[0], c=0;
        
        for(int i=0;i<n;i++){
            if(c==0) ans = nums[i];
            if(ans == nums[i])c++;
            else c--;
        }
        return ans;
    }
};