class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int>res;

        int n = nums.size();
        if(n==1) return nums;

        int c1 =0, x1 = nums[0], c2 = 0, x2 = nums[1];

        for(int i=0;i<n;i++){
            
            if(x1 == nums[i]) c1++;
            else if(x2 == nums[i]) c2++;
            else if(c1 == 0){
                c1=1;
                x1 = nums[i];
            }
            else if(c2 == 0){
                c2=1;
                x2 = nums[i];
            }
            else{
                c1--;
                c2--;
            }
            
        }

        c1=0, c2=0;
        for(int i=0;i<n;i++){
            if(nums[i]==x1) c1++;
            if(nums[i]==x2) c2++;
        }
        if(c1 > n/3) res.push_back(x1);
        if(x1 != x2 && (c2> n/3))
            res.push_back(x2);
        return res;

    }
};