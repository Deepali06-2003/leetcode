class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        
        int n = intervals.size();

        sort(intervals.begin(), intervals.end());

        int ans=0;
        int e = intervals[0][1];
        for(int i=1;i<n;i++){
            if(e > intervals[i][0]){
                ans++;
                e = min(e, intervals[i][1]);
            }
            else{
                e = intervals[i][1];
            }
        }

        return ans;
    }
};