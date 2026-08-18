class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        
        int n = position.size();
        vector<pair<int, int>>arr(n);
        for(int i=0;i<n;i++){
            arr[i] = {position[i] , speed[i]};
        }

        sort(arr.rbegin(), arr.rend());

        double curr = (double)(target-arr[0].first)/arr[0].second;
        int ans=1;

        for(int i=1;i<n;i++){
            double x = (double)(target-arr[i].first)/arr[i].second;

            if(x>curr){
                ans++;
                curr = x;
            }
        }
        return ans;
    }
};