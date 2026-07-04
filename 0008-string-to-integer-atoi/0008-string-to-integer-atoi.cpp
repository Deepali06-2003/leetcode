class Solution {
public:

    int myAtoi(string s) {
        
        int i = 0;
        int n = s.size();

        while(i<n && s[i]==' ') i++;

        int sign =1;
        if(i<n && (s[i]=='-' || s[i]=='+')){
            if(s[i]=='-') sign = -1;
            i++;
        }

        int ans=0;

        while(i<n && (s[i]>='0' && s[i]<='9')){

            int d = s[i]-'0';
            if(ans > INT_MAX/10 || (ans==INT_MAX/10 && d >7)){
                if(sign == -1) return INT_MIN;
                return INT_MAX;
            }
            ans = ans*10 +d;
            i++;
        }

        return sign*ans;
    }
};
