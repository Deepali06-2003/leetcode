class Solution {
public:
double helper(double x ,long long n){
    if(n==0)return 1.0;
    if(n==1)return x;

    double a = helper(x , n/2);
    if(n%2 ==0)return a*a;
    return a*a*x;
}
    double myPow(double x, int n) {
        
        if(n==0)return 1.0;
        if(n==1)return x;

        if(n<0){
            long long N = n;
            N = -N;
            return helper(1.0/x , N);
        }
        return helper(x , n);
    }
};