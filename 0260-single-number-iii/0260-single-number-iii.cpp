class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        

        int x=0;
        for(int i =0;i<nums.size();i++) x = x^nums[i];
        if(x>INT_MIN && x<INT_MAX)  x = x&(-x);

        int a=0, b=0;
        for(int i =0;i<nums.size();i++){

            if((x&nums[i]) == 0){
                a = a^ nums[i];
            }
            else{
                b = b^nums[i];
            }
        }

        return {a, b};
    }
};