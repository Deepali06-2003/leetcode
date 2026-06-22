class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        
        int s =1;
        for(int i = digits.size()-1;i>=0 ;i--){
            s = s+digits[i];
            digits[i]= s%10;
            s=s/10;
        }
        if(s!=0) digits.insert(digits.begin(), s);
        return digits;
    }
};