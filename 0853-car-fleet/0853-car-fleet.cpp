class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        
        int n = speed.size();
        vector<pair<int, int>> arr;
        for(int i =0;i<n;i++) arr.push_back({position[i] , speed[i] });

        sort(arr.rbegin(), arr.rend());

        int c=1;

        double ans = (double)(target - arr[0].first)/ arr[0].second;

        for(int i =1;i<n;i++){

            double x = (double)(target - arr[i].first)/ arr[i].second;
            if(x > ans){
                c++;
                ans = x;
            }
        }
        return c;
    }
};