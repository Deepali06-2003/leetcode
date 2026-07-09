class Solution {
public:

int helper(int n){
    int s =0;
    while(n!=0){
        int d = n%10;
        s = s+d;
        n = n/10;
    }
    return s;
}


    int countLargestGroup(int n) {
        
        unordered_map<int, int>mp;
        for(int i=1;i<=n;i++){
            int s = helper(i);
            mp[s]++;
        }

        vector<int>arr(n+1, 0);
        for(auto j: mp){
            arr[j.second] += 1;
        }

        for(int i=arr.size()-1;i>=0;i--){
            if(arr[i]!=0) return arr[i];
        }
        return 0;
    }
};