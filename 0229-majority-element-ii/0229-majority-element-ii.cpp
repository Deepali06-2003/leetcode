class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();

        int a = nums[0];
        int b ;
        if(n>=2 && nums[0] != nums[1]) b= nums[1];

        int c1 = 0, c2=0;

        for(int i=0;i<n;i++){
            if(nums[i] == a) c1++;
            else if(nums[i] == b) c2++;
            else if(c1 ==0){
                c1=1;
                a = nums[i];
            }
            else if(c2 ==0){
                c2 =1;
                b = nums[i];
            }
            else{
                c1--; c2--;
            }
        }

        c1 =0, c2=0;
        for(int i=0;i<n;i++){
            if(nums[i] == a) c1++;
            if(nums[i] == b) c2++;
        }

        vector<int>res;
        if(c1 > (n/3))res.push_back(a);
        if(a != b && c2>(n/3)) res.push_back(b);
        return res;
    }
};