class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        
        vector<pair<unsigned long long, pair<int, int>>>arr;
        
        for(int i=0;i<points.size();i++){
            unsigned long long d = ((points[i][0]*points[i][0]) + (points[i][1]*points[i][1]));
            arr.push_back({d, {points[i][0] , points[i][1]} });
        }

        sort(arr.begin(), arr.end());
        vector<vector<int>>res;

        for(int i=0;i<arr.size();i++){
            vector<int>temp = {arr[i].second.first , arr[i].second.second};
            res.push_back(temp);

            if(res.size()==k) return res;
        }
        return res;
    }
};