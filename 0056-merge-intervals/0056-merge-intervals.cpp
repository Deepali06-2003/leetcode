class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>>res;
        sort(intervals.begin(), intervals.end());

        int s = intervals[0][0], e = intervals[0][1];
        for(int i =1;i<intervals.size(); i++){
            if(intervals[i][0]<= e){
                e = max(intervals[i][1], e);
                s = min(intervals[i][0], s);
            }

            else{
                res.push_back({s, e});
                s= intervals[i][0];
                e= intervals[i][1];
            }
        }
        res.push_back({s, e});
        return res;
    }
};