class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>>res;

        sort(intervals.begin(), intervals.end());
        int n = intervals.size();

        int s = intervals[0][0];
        int e = intervals[0][1];

        for(int i =1;i<n;i++){
           if(intervals[i][0] <= e){
                e = max(e , intervals[i][1]);
                s = min(s, intervals[i][0]);
           }
           else{
            res.push_back({s, e});
            s = intervals[i][0];
            e = intervals[i][1];
           }
        }
        res.push_back({s, e});
        return res;
    }
};