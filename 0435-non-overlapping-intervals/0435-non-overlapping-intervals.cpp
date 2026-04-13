class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        
        int n = intervals.size();
        if(n==0 || n==1)return 0;

        sort(intervals.begin() , intervals.end());

        int ans=0;
        int e = intervals[0][1];
        

        for(int i =1;i<n;i++){
            if(intervals[i][0]< e){
                ans++;
                e = min(e , intervals[i][1]);
            }
            else e = intervals[i][1];
        }
        return ans;
    }
};