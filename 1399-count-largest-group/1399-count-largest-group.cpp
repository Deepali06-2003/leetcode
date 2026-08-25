class Solution {
public:

int helper(int n){
    int s=0;
    while(n!=0){
        s = s+ (n%10);
        n= n/10;
    }
    return s;
}

    int countLargestGroup(int n) {
        
        unordered_map<int, int>mp; //sum of digit , count

        for(int i=1;i<=n;i++){
            int sum = helper(i);
            mp[sum]++;
        }

        vector<int>freq(n+1, 0);
        for(auto j: mp){
            freq[j.second]++;
        }

        for(int i=n;i>=0;i--){
            if(freq[i]!=0) return freq[i];
        }
        return 0;

    }
};