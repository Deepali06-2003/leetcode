class Solution {
public:

int helper(int n){
    int c=0;
    while(n!=0){
        int r = n%2;
        if(r == 1) c++;
        n = n/2;
    }
    return c;
}
    vector<int> countBits(int n) {
        vector<int>res(n+1, 0);
        

        for(int i =1;i<=n;i++){
            res[i] = helper(i);
        }
        return res;
    }
};