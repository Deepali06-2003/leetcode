class Solution {
public:
    int jump(vector<int>& nums) {
        
        int jump =0, stop=0;
        int max_l =0;

        for(int i=0;i<nums.size()-1;i++){

            max_l = max(max_l , nums[i]+i);

            if(i == stop){
                jump++;
                stop = max_l;
            }
        }
        return jump;
    }
};