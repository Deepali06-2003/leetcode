class Solution {
public:
    int myAtoi(string s) {
        int ans=0;
        int i = 0, n = s.size();

        while(i<n && s[i]==' '){
            i++;
        }

        int sign =1;
        if(i<n && (s[i]=='+' || s[i]=='-')){
            if(s[i]=='-') sign = -1;
            i++;
        }

        while(i<n && (s[i]>='0' && s[i]<='9') ){
               int x = s[i]-'0';

            if(ans>INT_MAX/10 || (ans==INT_MAX/10 && x>7)){
                if(sign == -1) return INT_MIN;
                 return sign * INT_MAX;
            }
            ans = ans*10 + x;
            i++;
        }
        return ans*sign;
    }
};

