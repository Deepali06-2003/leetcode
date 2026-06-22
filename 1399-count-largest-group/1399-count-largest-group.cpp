class Solution {
public:
int helper(int n){
    int s=0;
    while(n !=0){
        s = s+ (n%10);
        n = n/10;
    }
    return s;
}
    int countLargestGroup(int n) {
                    //sum , count
        unordered_map<int  , int>mp;

        for(int i =1;i<=n;i++){
            int sum = helper(i);
            mp[sum]++;
        }

        vector<int>grp_f(n+1, 0);
        for(auto j: mp){
            grp_f[j.second]++;
        }

        for(int i = n;i>=0;i--){
            if(grp_f[i] > 0) return grp_f[i];
        }
        return -1;
    }
};