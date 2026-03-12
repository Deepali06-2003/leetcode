class Solution {
public:
    int pivotInteger(int n) {
        int s=0;
        for(int i =1; i<=n;i++) s= s+i;

       int ls = 0, rs = s;
       
       for(int i =1;i<=n ;i++){
        ls = ls+i;
        if(ls == rs)return i;
        rs = rs-i;
       }
       return -1;
    }
};