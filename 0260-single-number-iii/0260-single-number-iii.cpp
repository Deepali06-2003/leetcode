class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        
        int x=0;
        for(int i : nums) x = x^i;

        if(x>INT_MIN && x<INT_MAX) x = x&(-x);

        int a=0, b=0;

        for(int i : nums){
            if( (x&i) ==0) a= a^i;
            else b= b^i;
        }

        return {a, b};
    }
};