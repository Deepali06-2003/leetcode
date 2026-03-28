class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        int n = queries.size();

        // store {query, original_index}
        vector<pair<int,int>> q;
        for(int i = 0; i < n; i++){
            q.push_back({queries[i], i});
        }

        sort(q.begin(), q.end());
        sort(intervals.begin(), intervals.end());

        vector<int> res(n, -1);

        // {length, end}
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

        int j = 0;

        for(int i = 0; i < n; i++){
            int query = q[i].first;
            int idx = q[i].second;

            // push valid intervals
            while(j < intervals.size() && intervals[j][0] <= query){
                int l = intervals[j][0];
                int r = intervals[j][1];
                pq.push({r - l + 1, r});
                j++;
            }

            // remove invalid intervals
            while(!pq.empty() && pq.top().second < query){
                pq.pop();
            }

            if(!pq.empty()){
                res[idx] = pq.top().first;
            }
        }

        return res;
    }
};