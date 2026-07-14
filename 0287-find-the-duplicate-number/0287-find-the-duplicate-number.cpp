class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        
        int n = nums.size();

        int i=0;
        while(i<n){
            int curr = nums[i]-1;
            if((i<n) && (nums[i]>0 )&& (nums[i] != nums[curr]) ) swap(nums[i], nums[curr]);
            else i++;
        }

        for(int j=0;j<n;j++){
            if(nums[j] != j+1) return nums[j];
        }
        return -1;
    }
};