class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();

        int candidate =-1;
        for(int i=n-1 ;i>0;i--){
            if(nums[i-1] < nums[i]){
                candidate = i-1;
                break;
            }
        }
        if( candidate != -1){
            int right_greater = candidate;

            for(int j=n-1; j>= candidate+1 ; j--){
                if(nums[candidate] < nums[j] ){
                    right_greater = j;
                    break;
                }
            }

            swap(nums[right_greater], nums[candidate]);
        }
        reverse(nums.begin()+candidate+1, nums.end());
    }
};