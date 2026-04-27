class Solution {
public:
double helper(double x, long long n){
    if(n ==0)return 1;
    if(n==1)return x;

    double y = helper(x, n/2);

    if(n%2==0) return y*y;
    return y*y*x;
}
    double myPow(double x, int n) {
        
        if(n ==0)return 1;
        if(n<0) {
           // int N = -n;
            long long N = n;
            N = -N;
            return helper(1.0/x, N);
        }
        return helper(x, n);
    }
};