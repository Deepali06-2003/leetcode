class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        int n = intervals.size();

        vector<pair<int, int>>query;
        for(int i=0;i<queries.size();i++)   query.push_back({queries[i], i});

        sort(query.begin(), query.end());
        sort(intervals.begin(), intervals.end());

        priority_queue<pair<int, int> , vector<pair<int, int>>, greater<pair<int, int>>>pq;

        vector<int>res(queries.size(), -1);
        int j=0;
        for(int i=0;i<query.size();i++){
            int q = query[i].first;
            int idx = query[i].second;

            while(j<n && intervals[j][0]<=q){
                pq.push({ intervals[j][1]-intervals[j][0]+1 , intervals[j][1] });
                j++;
            }

            while(!pq.empty() && pq.top().second < q) pq.pop();

            if(!pq.empty()) res[idx] = pq.top().first;
        }

        return res;
    }
};