class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();

        int i =0;
        while(i<n){
            int c = nums[i];
            if(c<n && (nums[i]!=nums[c])) swap(nums[i], nums[c]);
            else i++;
        }

        for(int j=0;j<n;j++){
            if(nums[j] != j) return j;
        }
        return i;
    }
};