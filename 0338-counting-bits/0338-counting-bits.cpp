class Solution {
public:
int helper(int x){

    int c =0;
    while(x!=0){
        if((x%2)==1) c= c+1;
        x= x/2;
    }
    return c;
}
    vector<int> countBits(int n) {
        vector<int> ans(n+1, 0);
        for(int i=1;i<=n;i++){
            ans[i] = helper(i);
        }
         return ans;
    }
};