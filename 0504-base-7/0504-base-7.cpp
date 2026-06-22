class Solution {
public:
    string convertToBase7(int num) {

        if(num == 0) return "0";

        string ans ="";

        bool is_Neg = (num<0);
        
        while(num!=0){
            int d = num%7;
            ans = to_string(abs(d)) + ans;
            num = num/7;
        }
        
        if(is_Neg) ans = "-" + ans;
        return ans;
    }
};