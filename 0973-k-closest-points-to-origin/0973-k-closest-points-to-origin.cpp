class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<pair<double , pair<int, int>>> res;

        for(int i =0;i<points.size(); i++){

            double x = (1LL*points[i][0]*points[i][0]) + (1LL*points[i][1] * points[i][1]);
            res.push_back({x, {points[i][0] , points[i][1]} });
        }

        sort(res.begin(), res.end());
        vector<vector<int>>ans;

        for(int i =0;i<k;i++){
            ans.push_back({res[i].second.first , res[i].second.second});
        }
        return ans;
    }
};