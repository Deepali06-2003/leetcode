class Solution {
public:
    int jump(vector<int>& nums) {
        
        int j = 0, stop = 0;
        int max_i = 0;

        for(int i=0;i<nums.size()-1;i++){
            max_i = max(max_i, nums[i]+i);

            if(stop == i){
                stop = max_i;
                j++;
            }
        }

        return j;
    }
};