class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        
        int n = nums.size();
        int i =0;

        while(i<n){
            int c = nums[i]-1;
            if(c<n && nums[i]!=nums[c]) swap(nums[i], nums[c]);
            else i++;
        }

        for(int j=0;j<n;j++){
            if(j != (nums[j]-1))return nums[j];
        }
        return n+1;
    }
};