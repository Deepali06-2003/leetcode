class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        
        int n = nums.size();


        int curr_idx = -1;

        for(int i=n-1;i>0;i--){
            if(nums[i] > nums[i-1]){
                curr_idx = i-1;
                break;
            }
        }

        if(curr_idx != -1){

            int r_idx = curr_idx;

            for(int i=n-1;i>curr_idx ; i--){
                if(nums[i] > nums[curr_idx]){ r_idx =i;
                break;}
            }

            swap(nums[curr_idx], nums[r_idx]);
        }

        reverse(nums.begin()+curr_idx+1 , nums.end());
    }
};