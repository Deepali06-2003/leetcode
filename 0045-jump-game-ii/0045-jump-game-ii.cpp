class Solution {
public:
    int jump(vector<int>& nums) {
        int jump =0;
        int max_i =0, stop;

        for(int i =0;i<nums.size()-1;i++){
            max_i = max(max_i , nums[i]+i);

            if( i == stop ){
                jump++;
                stop = max_i;
            }
        }

        return jump;
    }
};