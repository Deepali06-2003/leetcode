class Solution {
public:
    string multiply(string num1, string num2) {
        int n = num1.size() , m = num2.size();

        if(num1=="0" || num2=="0") return "0";

        vector<int>res(n+m, 0);
        int i=n-1, j=m-1;
        
        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
            int x = num1[i]-'0';
            int y = num2[j]-'0';
            
            int s = res[i+j+1]+(x*y);
            res[i+j+1] = s%10;
            res[i+j] = res[i+j]+(s/10);
            
        }
        }
        
        string ans ="";
        for(int i:res){
            if( !(i==0 && ans.empty())) ans += (i+'0');
        }
        if(ans.empty()) "0";
        return ans;
    }
};