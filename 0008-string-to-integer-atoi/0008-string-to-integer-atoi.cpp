class Solution {
public:

    int myAtoi(string s) {
        
        int i = 0;
        int n = s.size();

        //space
        while(i<n && s[i]==' ') i++;

        //sign
        int sign = 1;
        if(i<n && (s[i]=='-' || s[i]=='+') ){
            if(s[i] == '-')sign = -1;
            i++;
        }


        int ans=0;
        while(i<n && (s[i]>='0' && s[i]<='9')){
            int dig = int(s[i]-'0');

            if(ans > INT_MAX/10 || (ans == INT_MAX/10 && dig > 7)) return sign == 1 ? INT_MAX : INT_MIN;

            ans = ans*10 + dig;
            i++;
        }

        if(sign == -1)return -1*ans;
        return ans;
    }
};
