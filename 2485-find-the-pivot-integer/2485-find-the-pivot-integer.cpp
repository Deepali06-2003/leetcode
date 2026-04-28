class Solution {
public:
    int pivotInteger(int n) {

        int ls = 0;
        int rs = (n*(n+1))/2;
        
        for(int i =1;i<=n;i++){
            rs = rs - i;
            if(rs == ls) return i;
            ls = ls+i;
        }
        return -1;
    }
};