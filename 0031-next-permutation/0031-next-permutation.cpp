class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        

        int n = nums.size();

        int cand_idx = -1;
        for(int i = n-1;i>0;i--){
            if(nums[i-1] < nums[i]){
                cand_idx = i-1;
                break;
            }
        }

        if(cand_idx != -1){

            int right_grt = cand_idx;
            for(int i=n-1 ; i>cand_idx ;i--){
                if(nums[i] > nums[cand_idx]){
                    right_grt = i;
                    break;
                }
            }

            swap(nums[cand_idx] , nums[right_grt]);
        }

        reverse(nums.begin()+cand_idx+1 , nums.end());
    }
};