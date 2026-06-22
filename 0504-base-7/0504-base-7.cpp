class Solution {
public:
    string convertToBase7(int num) {
        string ans ="";

        bool is_Neg = false;
       if(num<0)is_Neg = true;
        
        while(num!=0){
            int d = num%7;
            ans = to_string(abs(d)) + ans;
            //ans.append(to_string(d), 1);
            num = num/7;
        }
        if(ans.empty()) return "0";
        if(is_Neg == true) ans = "-" + ans;
        return ans;
    }
};