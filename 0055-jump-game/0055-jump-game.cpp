class Solution {
public:
    bool canJump(vector<int>& nums) {
       int max_i =0;

       for(int i =0;i<nums.size();i++){
        if(i>max_i)return false;

        max_i = max(max_i , nums[i]+i);

       }
       return true;
    }
};