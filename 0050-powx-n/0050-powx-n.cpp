class Solution {
public:
double helper(double x, long long n){
    if(n==0) return 1.0;
    if(n==1) return x;

    double temp = helper(x, n/2);

    if(n%2==0) return temp * temp;
    return temp * temp* x;
}
    double myPow(double x, int n) {
        if( n==0 ) return 1.0;
        if(n==1) return x;

        if(n<0){
            long long int N = n;
            N = -N;
            return helper(1/x, N);
        }
        return helper(x, n);
    }
};