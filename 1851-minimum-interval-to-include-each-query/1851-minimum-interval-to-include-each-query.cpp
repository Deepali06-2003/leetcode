class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        int n = queries.size();
     vector<pair<int, int>>query;
     for(int i=0;i<n;i++){
        query.push_back({queries[i], i});
     }  
     sort(query.begin(), query.end());
     sort(intervals.begin(), intervals.end());

     vector<int>res(n, -1); 
     priority_queue<pair<int, int> ,vector<pair<int, int>>, greater<pair<int, int>>>pq;
        //pair<int, int>

            int j=0;
     for(int i=0;i<n;i++){
        int q = query[i].first;
        int x = query[i].second;

        while(j<intervals.size() && intervals[j][0]<=q){ 
            pq.push({intervals[j][1]-intervals[j][0]+1 , intervals[j][1]});
            j++;
        }
        while(!pq.empty() && pq.top().second < q) pq.pop();

        if(!pq.empty()) res[x]=pq.top().first;
     }
     return res;
    }
};