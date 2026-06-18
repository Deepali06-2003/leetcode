class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        
        int n = intervals.size();
        sort(intervals.begin() , intervals.end());
        int c=0;

        int s = intervals[0][0] , e =intervals[0][1];
        for(int i =1;i<n;i++){
            if(intervals[i][0] < e){
                e= min(intervals[i][1], e);
                c++;
            }
            else e = intervals[i][1];
        }
        return c;
    }
};